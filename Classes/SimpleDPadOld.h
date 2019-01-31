////
////  SimpleDPad.h
////  pompadroid
////
////  Created by Quang Vu on 1/25/19.
////
//
//#ifndef SimpleDPadOLD_h
//#define SimpleDPadOLD_h
//
//#include "cocos2d.h"
//
//USING_NS_CC;
//
//class SimpleDPadOLD : public Sprite
//{
////    Sprite* _joystick;
////    Sprite* _joystick_bg;
////    void _activityJoystick(Vec2 position);
////    void _inactivityJoystick();
////    void _updateJoystick(Vec2 direction, float distance);
////public:
////    virtual bool init();
////    CREATE_FUNC(SimpleDPad);
////
////    virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
////    virtual void onTouchesMoved(const std::vector<Touch*>& touches, Event* event);
////    virtual void onTouchesEnded(const std::vector<Touch*>& touches, Event* event);
////
////    CC_SYNTHESIZE(SimpleDPadDelegate*, _delegator, Delegator);
//};
//
//
//class SimpleDPadDelegateOLD
//{
//public:
//    // TODO: Why assign 0 here?
//    //    virtual void onWalk(Vec2 direction, float distance) = 0;
//    //    virtual void onAttack() = 0;
//    //    virtual void onStop() = 0;
//    void simpleDPadDidChangeDirectionTo(SimpleDPad *simpleDPad, Point direction);
//    void simpleDPadIsHoldingDirection(SimpleDPad *simpleDPad, Point direction);
//    void simpleDPadTouchEnded(SimpleDPad *simpleDPad);
//};
//
////#endif /* SimpleDPadOLD_h */
