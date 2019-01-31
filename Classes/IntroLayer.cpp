//
//  IntroLayer.cpp
//  pompadroid
//
//  Created by Quang Vu on 1/24/19.
//

#include "IntroLayer.h"
#include "GameScene.h"

bool IntroLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    // Code Here
    
    return true;
}

Scene* IntroLayer::createScene()
{
    auto scene = Scene::create();
    
    auto layer = IntroLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

void IntroLayer::onEnter()
{
    Layer::onEnter();
//
    Size visibleSize = Director::getInstance()->getVisibleSize();
//
    Sprite* background = Sprite::create("Default.png");
    background->setRotation(90.0);
    background->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(background);
    this->scheduleOnce(SEL_SCHEDULE(&IntroLayer::makeTransition), 1.0);
}

void IntroLayer::makeTransition(float delta)
{
    // TODO: Why can not use GameScene::create ?
//    Director::getInstance()->replaceScene(TransitionFade::create(1.0, GameScene::create(), Color3B::WHITE));
    
    Director::getInstance()->replaceScene(TransitionFade::create(1.0, GameScene::createScene(), Color3B::WHITE));
}
