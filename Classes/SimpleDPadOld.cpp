////
////  SimpleDPad.cpp
////  pompadroid
////
////  Created by Quang Vu on 1/25/19.
////
//
//#include "SimpleDPadOld.h"
//
//bool SimpleDPadOld::init()
//{
//    bool ret = false;
//    do {
//        CC_BREAK_IF(!Layer::init());
//        
//        _joystick = Sprite::create("joystick.png");
//        _joystick_bg = Sprite::create("joystick_bg.png");
//        this->addChild(_joystick_bg);
//        this->addChild(_joystick);
//        _inactivityJoystick();
//        
//        auto touchListener = EventListenerTouchAllAtOnce::create();
//        touchListener->onTouchesBegan = CC_CALLBACK_2(SimpleDPad::onTouchesBegan, this);
//        _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);
//    } while(0);
//    
//    return ret;
//}
//
//// Touches
//void SimpleDPadOld::onTouchesBegan(const std::vector<Touch*>& touches, Event* event)
//{
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    for(int i = 0; i < touches.size(); ++i){
//        Touch *t = touches[i];
//        Point p = t->getLocation();
//        if (p.x <= visibleSize.width / 2) {
//            _activityJoystick(p);
//        } else {
//            _delegator->onAttack();
//        }
//    }
//}
//
//void SimpleDPadOld::onTouchesMoved(const std::vector<Touch*>& touches, Event* event)
//{
//    Size visibleSize = Director::getInstance()->getVisibleSize();
//    Touch* t = touches[0];
//    Point start = t->getStartLocation();
//    if(start.x > visibleSize.width/2) {
//        return;
//    }
//    Point p = t->getLocation();
//    float distance = start.getDistance(p);
////    Point direction = (p - start).normalize();
//    Point direction = (p - start).getNormalized();
//    _updateJoystick(direction, distance);
//    _delegator->onWalk(direction, distance);
//}
//
////void SimpleDPad::ccTouchesMoved(Set *ts, Event *e)
////{
////    Size winSize = Director::getInstance()->getWinSize();
////    SetIterator iter = ts->begin();
////    Touch *t = (Touch*)(*iter);
////    Point start = t->getStartLocation();
//
////    if (start.x > winSize.width / 2) {
////        return;
////    }
////
////    Point p = t->getLocation();
////    float distance = start.getDistance(p);
////    Point direction = (p - start).normalize();
////
////    _updateJoystick(direction, distance);
////    _delegator->onWalk(direction, distance);
////}
//
//void SimpleDPadOld::onTouchesEnded(const std::vector<Touch*>& touches, Event* event)
//{
//    CCLOG("onTouchesEnded");
////    if (_joystick_bg->isVisible()) {
////        _inactivityJoystick();
////        _delegator->onStop();
////    }
//}
//
//void SimpleDPadOld::_activityJoystick(Vec2 position)
//{
//    CCLOG("onTouchesEnded");
////    _joystick->setPosition(position);
////    _joystick_bg->setPosition(position);
////    _joystick->setVisible(true);
////    _joystick_bg->setVisible(true);
//}
//
//void SimpleDPadOld::_inactivityJoystick()
//{
//    _joystick->setPosition(_joystick_bg->getPosition());
//    _joystick->setVisible(false);
//    _joystick_bg->setVisible(false);
//}
//
//void SimpleDPad::_updateJoystick(Vec2 direction, float distance)
//{
//    Point start = _joystick_bg->getPosition();
//
//    if (distance < 32) {
//        _joystick->setPosition(start + (direction * distance));
//    } else if (distance > 96) {
//        _joystick->setPosition(start + (direction * 64));
//    } else {
//        _joystick->setPosition(start + (direction * 32));
//    }
//}
