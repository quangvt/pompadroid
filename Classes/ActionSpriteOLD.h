////
////  ActionSprite.h
////  pompadroid
////
////  Created by Quang Vu on 1/24/19.
////
//
//#ifndef ActionSpriteOLD_h
//#define ActionSpriteOLD_h
//
//#include "cocos2d.h"
//#include "Defines.h"
//
//USING_NS_CC;
//
//class ActionSpriteOLD : public Sprite
//{
//private:
//    bool _changeState(ActionState state);
//    // schedule method
////    void update(float delta);
//    
//protected:
//    static Animation *createAnimation(const char *fmt, int count, float fps);
//
//public:
////    ActionSprite();
////    ~ActionSprite();
//    
//    // action methods
//    void idle();
//    void walk();
//    void attack();
//    void hurt();
//    void knockout();
//    
//    // actions
//    CC_SYNTHESIZE_RETAIN(Action*, _idleAction, IdleAction);
//    CC_SYNTHESIZE_RETAIN(Action*, _attackAction, AttackAction);
//    CC_SYNTHESIZE_RETAIN(Action*, _hurtAction, HurtAction);
//    CC_SYNTHESIZE_RETAIN(Action*, _knockoutAction, KnockoutAction);
//    CC_SYNTHESIZE_RETAIN(Action*, _walkAction, WalkAction);
//    
//    //states
//    CC_SYNTHESIZE(ActionState, _currentState, ActionState);
//    
////    CC_SYNTHESIZE(unsigned int, _hp, HP);
////    CC_SYNTHESIZE(unsigned int, _atk, ATK);
//    
//    // attributes
//    CC_SYNTHESIZE(float, _walkSpeed, WalkSpeed);
//    CC_SYNTHESIZE(float, _hitPoints, HitPoints);
//    CC_SYNTHESIZE(float, _damage, Damage);
//    
//    // movement
//    CC_SYNTHESIZE(Point, _velocity, Velocity);
//    CC_SYNTHESIZE(Point, _desiredPosition, DesiredPosition);
//    
//    // measurements
//    CC_SYNTHESIZE(float, _centerToSides, CenterToSides);
//    CC_SYNTHESIZE(float, _centerToBottom, CenterToBottom);
//};
//#endif /* ActionSpriteOLD_h */
