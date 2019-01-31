////
////  ActionSprite.cpp
////  pompadroid
////
////  Created by Quang Vu on 1/24/19.
////
//#include "ActionSpriteOLD.h"
//
////ActionSprite::ActionSprite()
////{
////    _idleAction = NULL;
////    _walkAction = NULL;
////    _attackAction = NULL;
////    _hurtAction = NULL;
////    _knockoutAction = NULL;
////}
////
////ActionSprite::~ActionSprite()
////{}
//
//void ActionSpriteOLD::idle()
//{
//    if (_changeState(ACTION_STATE_IDLE)) {
//        runAction(_idleAction);
//    }
//}
//
//void ActionSpriteOLD::attack()
//{
//    if (_changeState(ACTION_STATE_ATTACK)) {
//        runAction(_attackAction);
//    }
//
//}
//
//void ActionSpriteOLD::walk()
//{
//    if (_changeState(ACTION_STATE_WALK)) {
//        runAction(_walkAction);
//    }
//}
//
////void ActionSpriteOLD::hurt()
////{
////    if (_changeState(ACTION_STATE_HURT)) {
////        runAction(_hurtAction);
////    }
////}
////
////void ActionSpriteOLD::knockout()
////{
////    if (_changeState(ACTION_STATE_KNOCKOUT)) {
////        runAction(_knockoutAction);
////    }
////}
//
//bool ActionSpriteOLD::_changeState(ActionState state)
//{
//    bool ret = false;
//
//    if (_currentState == ACTION_STATE_KNOCKOUT) {
//        goto change_state_failed;
//    }
//
//    if (_currentState == state) {
//        goto change_state_failed;
//    }
//
//    this->stopAllActions();
//
//    _currentState = state;
//    ret = true;
//
//change_state_failed:
//    return ret;
//}
//
///**
// *
// */
//Animation *ActionSpriteOLD::createAnimation(const char *fmt, int count, float fps)
//{
//    auto frames = new Vector<SpriteFrame*>(2);
//    char str[100];
//    for (int i = 0; i < count; i++) {
//        sprintf(str, fmt, i);
//        SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
//        frames->pushBack(frame);
//    }
//    return Animation::createWithSpriteFrames(*frames, 1 / fps);
//}
