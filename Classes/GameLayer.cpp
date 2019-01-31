//
//  GameLayer.cpp
//  pompadroid
//
//  Created by Quang Vu on 1/24/19.
//

#include <ctime>
#include "GameLayer.h"
#include "GameScene.h"

bool GameLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    // audio
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("Sounds/latin_industries.aifc");
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("Sounds/latin_industries.aifc");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sounds/pd_hit0.caf");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sounds/pd_hit1.caf");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sounds/pd_herodeath.caf");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sounds/pd_botdeath.caf");
    
    // touch
    auto touchListener = EventListenerTouchAllAtOnce::create();
    touchListener->onTouchesBegan = CC_CALLBACK_2(GameLayer::onTouchesBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    // tilemap
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    _map = TMXTiledMap::create("Sprites/pd_tilemap.tmx");
    _map->setPosition(origin);
    this->addChild(_map, -6);
    
    // actors
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Sprites/pd_sprites.plist");
    _actors = SpriteBatchNode::create("Sprites/pd_sprites.pvr.ccz");
    this->addChild(_actors, -5);
    
    // init objects
    this->initHero();
    this->initRobots();
    
    // update
    this->scheduleUpdate();
    
    return true;
}

void GameLayer::initHero()
{
    _hero = Hero::create();
    _actors->addChild(_hero);
    _hero->setPosition(Vec2(_hero->getCenterToSides(), 80)); // 80? free y value
    _hero->setDesiredPosition(_hero->getPosition());
    _hero->idle();
}

void GameLayer::initRobots()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    int robotCount = 50;
    this->_robots = new Vector<Robot*>(50);
    for (int i = 0; i < robotCount; i++)
    {
        Robot *robot = Robot::create();
        _actors->addChild(robot);
        _robots->pushBack(robot);
        
        int minX = visibleSize.width + robot->getCenterToSides();
        int maxX = _map->getMapSize().width * _map->getTileSize().width - robot->getCenterToSides();
        int minY = robot->getCenterToBottom();
        int maxY = 3 * _map->getTileSize().height + robot->getCenterToBottom(); // 4 bottom tiles
        // TODO: Make clear this code
        // This make size of hitbox is negative => can not collide
//        robot->setScaleX(-1.0);
        float rx = minX + (rand() % 100) * (maxX - minX) / 100;
        float ry = minY + (rand() % 100) * (maxY - minY) / 100;
        robot->setPosition(Vec2(rx, ry));
        robot->setDesiredPosition(robot->getPosition());
        robot->idle();
    }
}

// Touches
void GameLayer::onTouchesBegan(const std::vector<Touch*>& touches, Event *event)
{
    CCLOG("GameLayer::onTouchesBegan");
    _hero->attack();
    if(_hero->getActionState() == ACTION_STATE_ATTACK)
    {
        CCLOG("_hero.actual (%f, %f, %f, %f))", _hero->getAttackBox().actual.origin.x,
              _hero->getAttackBox().actual.origin.y,
              _hero->getAttackBox().actual.size.width,
              _hero->getAttackBox().actual.size.height);
        for (auto robot : *_robots)
        {
            if (robot->getActionState() != ACTION_STATE_KNOCKOUT)
            {
                // TODO: why 10, 20?
                // x: 29 + 29 + 20 = ToSides of Hero + ToSides of Robot + AttackBox width
                if (fabsf(_hero->getPosition().y - robot->getPosition().y) < 10 &&
                    fabsf(_hero->getPosition().x - robot->getPosition().x) < 78)
                {
                    CCLOG("robot.actual (%f, %f, %f, %f))", robot->getHitBox().actual.origin.x,
                          robot->getHitBox().actual.origin.y,
                          robot->getHitBox().actual.size.width,
                          robot->getHitBox().actual.size.height);
                    CCLOG("_hero.position (%f, %f)", _hero->getPosition().x, _hero->getPosition().y);
                    CCLOG("robot.position(%f, %f)", robot->getPosition().x, robot->getPosition().y);
                    if (_hero->getAttackBox().actual.intersectsRect(robot->getHitBox().actual))
                    {
                        CCLOG("PUNCH");
                        robot->hurtWithDamage(_hero->getDamage());
                    }
                }
            }
        }
    }
}

// Override Abstract (Protocols)
void GameLayer::didChangeDirectionTo(SimpleDPad *simpleDPad, Point direction)
{
//    CCLOG("GameLayer::didChangeDirectionTo");
    _hero->walkWithDirection(direction);
}

void GameLayer::simpleDPadTouchEnded(SimpleDPad *simpleDPad)
{
//    CCLOG("GameLayer::simpleDPadTouchEnded");
    if (_hero->getActionState() == ACTION_STATE_WALK)
    {
        _hero->idle();
    }
}

void GameLayer::isHoldingDirection(SimpleDPad *simpleDPad, Point direction)
{
//    CCLOG("GameLayer::isHoldingDirection");
    _hero->walkWithDirection(direction);
}

// Update
void GameLayer::update(float delta)
{
    _hero -> update(delta);
    this->updatePositions();
    this->updateRobots(delta); // AI Robot
    this->reorderActors();
    this->setViewpointCenter(_hero->getPosition());
}

void GameLayer::updatePositions()
{
    float posX = MIN(_map->getMapSize().width * _map->getTileSize().width
                        - _hero->getCenterToSides(),
                     MAX(_hero->getCenterToSides(), _hero->getDesiredPosition().x));
    float posY = MIN(3 * _map->getTileSize().height + _hero->getCenterToBottom(),
                     MAX(_hero->getCenterToBottom(), _hero->getDesiredPosition().y));
    _hero->setPosition(Vec2(posX, posY));
    
    // AI Robot
    for (auto robot : *_robots)
    {
        posX = MIN(_map->getMapSize().width * _map->getTileSize().width - robot->getCenterToSides(),
                   MAX(robot->getCenterToSides(), robot->getDesiredPosition().x));
        posY = MIN(3 * _map->getTileSize().height + robot->getCenterToBottom(),
                   MAX(robot->getCenterToBottom(), robot->getDesiredPosition().y));
        robot->setPosition(Vec2(posX, posY));
    }
}

void GameLayer::setViewpointCenter(Vec2 position)
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    int left = MAX(position.x, visibleSize.width/2);
    int right = (_map->getMapSize().width * _map->getTileSize().width) - visibleSize.width/2;
    int bottom = MAX(position.y, visibleSize.height/2);
    int top = (_map->getMapSize().height * _map->getTileSize().height) - visibleSize.height/2;
    int x = MIN(left, right);
    int y = MIN(bottom, top);
    Vec2 actualPosition = Vec2(x, y);
    Vec2 centerOfView = Vec2(visibleSize.width/2, visibleSize.height/2);
    Vec2 shift = centerOfView - actualPosition;
    this->setPosition(shift);
}

void GameLayer::reorderActors()
{
    for (auto child : _actors->getChildren())
    {
        _actors->reorderChild(child, (_map->getMapSize().height * _map->getTileSize().height) - child->getPosition().y);
    }
}

// Can use FOLLOW action?
void GameLayer::updateRobots(float delta)
{
    int alive = 0;
    float distanceSQ;
    int randomChoice = 0;
    Size visibleSize = Director::getInstance()->getVisibleSize();
    for(auto robot : *_robots)
    {
        robot->update(delta);
        if(robot->getActionState() != ACTION_STATE_KNOCKOUT)
        {
            //1
            alive++;
            
            //2
            if (time(0) > robot->getNextDecisionTime())
            {
                distanceSQ = robot->getPosition().getDistanceSq(_hero->getPosition());
                
                //3
                if (distanceSQ <= 50*50)
                {
                    robot->setNextDecisionTime(time(0) + ((rand() % 5) + 1)/10);
                    randomChoice = rand() % 2;
                    if (randomChoice == 0)
                    {
                        if (_hero->getPosition().x > robot->getPosition().x)
                        {
                            robot->setScaleX(1.0);
                        } else {
                            robot->setScaleX(-1.0);
                        }
                        
                        //4
                        robot->attack();
                        if (robot->getActionState() == ACTION_STATE_ATTACK)
                        {
                            if (fabsf(_hero->getPosition().y - robot->getPosition().y) < 10)
                            {
                                if (_hero->getHitBox().actual.intersectsRect(robot->getAttackBox().actual))
                                {
                                    _hero->hurtWithDamage(robot->getDamage());
                                    
                                    //end game checker here
                                    if (_hero->getActionState() == ACTION_STATE_KNOCKOUT && _hUD->getChildByTag(5) == NULL) {
                                        this->endGame();
                                    }
                                }
                            }
                        }
                    } else
                    {
                        robot->idle();
                    }
                } // end if (distanceSQ <= 50*50)
                else if (distanceSQ <= visibleSize.width * visibleSize.width)
                {
                    // 5
                    robot->setNextDecisionTime(time(0) + ((rand() % 5) + 1)/10);
                    randomChoice = rand() % 3;
                    if (randomChoice == 0)
                    {
                        Vec2 moveDirection = (_hero->getPosition() - robot->getPosition()).getNormalized();
                        robot->walkWithDirection(moveDirection);
                    } else {
                        robot->idle();
                    }
                } // end else if (distanceSQ <= visibleSize.width * visibleSize.width)
            } // end if (time(0) > robot->getNextDecisionTime())
        } // end if(robot->getActionState() != ACTION_STATE_KNOCKOUT)
    } // end for(auto robot : *_robots)
    
    // end game checker here
    if (alive == 0 && _hUD->getChildByTag(5) == NULL)
    {
        this->endGame();
    }
}

void GameLayer::endGame()
{
    Size visibleSize = Director::getInstance()->getVisibleSize();
    auto replayLabel = Label::createWithTTF("REPLAY", "fonts/Marker Felt.ttf", 30.0f);
    auto replayMenuItem =  MenuItemLabel::create(replayLabel);
    replayMenuItem->setCallback(CC_CALLBACK_0(GameLayer::restartGame, this));
    auto menu = Menu::create(replayMenuItem, NULL);
    menu->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    menu->setTag(5);
    _hUD->addChild(menu, 5);
}

void GameLayer::restartGame()
{
    Director::getInstance()->replaceScene(GameScene::createScene());
}
