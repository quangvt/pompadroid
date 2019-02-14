//
//  SimpleDPad.cpp
//  pompadroid
//
//  Created by Quang Vu on 1/25/19.
//

#include "SimpleDPad.h"

SimpleDPad* SimpleDPad::dPadWithFile(const std::string& filename, float radius)
{
    SimpleDPad* simpleDPad = new SimpleDPad();
    if(simpleDPad && simpleDPad->initWithFile(filename, radius))
    {
        simpleDPad->autorelease();
        return simpleDPad;
    }
    return NULL;
}

bool SimpleDPad::initWithFile(const std::string& filename, float radius)
{
    //if(!Sprite::initWithFile(filename))
    if(!Sprite::initWithFile(filename, Rect(0.0, 0.0, radius*2, radius*2)))
    {
        return false;
    }
    // Touch
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(SimpleDPad::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(SimpleDPad::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(SimpleDPad::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    _radius = radius;
    _direction = Point::ZERO;
    _isHeld = false;
    this->scheduleUpdate();
    return true;
}

bool SimpleDPad::onTouchBegan(Touch* touch, Event* event)
{
    CCLOG("SimpleDPad::onTouchBegan");
    Vec2 locInView = touch->getLocationInView();
    Vec2 locInGL = Director::getInstance()->convertToGL(locInView);
    float distanceSQ = _position.getDistanceSq(locInGL);
    if (distanceSQ <= _radius * _radius) {
        //get angle 8 directions
        this->updateDirectionForTouchLocation(locInGL);
        _isHeld = true;
        return true; // Swallow touch
    }
    return false;
}

void SimpleDPad::onTouchMoved(Touch* touch, Event* event)
{
//    CCLOG("SimpleDPad::onTouchMoved");
    Vec2 location = Director::getInstance() -> convertToGL(touch->getLocationInView());
    this->updateDirectionForTouchLocation(location);
}

void SimpleDPad::onTouchEnded(Touch* touch, Event* event)
{
//    CCLOG("SimpleDPad::onTouchEnded");
    _direction = Point::ZERO;
    _isHeld = false;
    _delegator->simpleDPadTouchEnded(this);
}

//void SimpleDPad::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
//{
//    CCLOG("SimpleDPad::onTouchesBegan");
//    for (auto &touch : touches)
//    {
//        Vec2 locInView = touch->getLocationInView();
//        //CCLOG("SimpleDPad::onTouchBegin::locInView (%f, %f)", locInView.x, locInView.y);
//        Vec2 locInGL = Director::getInstance()->convertToGL(locInView);
//        float distanceSQ = _position.getDistanceSq(locInGL);
//        if (distanceSQ <= _radius * _radius) {
//            //get angle 8 directions
//            this->updateDirectionForTouchLocation(locInGL);
//            _isHeld = true;
////            return true; // Swallow touch
//            CCLOG("SimpleDPad::onTouchesBegan::Swallow");
//        }
//    }
//}
//
//void SimpleDPad::onTouchMoved(const Touch* touch, Event* event)
//{
//    //    CCLOG("SimpleDPad::onTouchMoved");
//    Vec2 location = Director::getInstance() -> convertToGL(touch->getLocationInView());
//    this->updateDirectionForTouchLocation(location);
//}
//
//void SimpleDPad::onTouchEnded(const Touch* touch, Event* event)
//{
//    //    CCLOG("SimpleDPad::onTouchEnded");
//    _direction = Point::ZERO;
//    _isHeld = false;
//    _delegator->simpleDPadTouchEnded(this);
//}

void SimpleDPad::updateDirectionForTouchLocation(Vec2 location)
{
//    CCLOG("SimpleDPad::updateDirectionForTouchLocation");
//    float radians = ccpToAngle(location - getPosition());
    float radians = (location - getPosition()).getAngle();
    
    float degrees = -1 * CC_RADIANS_TO_DEGREES(radians);

    if (degrees <= 22.5 && degrees >= -22.5) {
        //right
        _direction = Vec2(1.0, 0.0);
    } else if (degrees > 22.5 && degrees < 67.5) {
        //bottomright
        _direction = Vec2(1.0, -1.0);
    } else if (degrees >= 67.5 && degrees <= 112.5) {
        //bottom
        _direction = Vec2(0.0, -1.0);
    } else if (degrees > 112.5 && degrees < 157.5) {
        //bottomleft
        _direction = Vec2(-1.0, -1.0);
    } else if (degrees >= 157.5 || degrees <= -157.5) {
        //left
        _direction = Vec2(-1.0, 0.0);
    } else if (degrees < -22.5 && degrees > -67.5) {
        //topright
        _direction = Vec2(1.0, 1.0);
    } else if (degrees <= -67.5 && degrees >= -112.5) {
        //top
        _direction = Vec2(0.0, 1.0);
    } else if (degrees < -112.5 && degrees > -157.5) {
        //topleft
        _direction = Vec2(-1.0, 1.0);
    }
    _delegator->didChangeDirectionTo(this, _direction);
}

void SimpleDPad::update(float delta)
{
    if(_isHeld)
    {
        _delegator->isHoldingDirection(this, _direction);
    }
}
