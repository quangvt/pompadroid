//
//  ActionSprite.h
//  pompadroid
//
//  Created by Quang Vu on 1/28/19.
//

#ifndef ActionSprite_h
#define ActionSprite_h

#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "Defines.h"

USING_NS_CC;

class ActionSprite : public Sprite
{
    void transformBoxes();

protected:
    
    /**
     * Create animation from SpriteFrameCache
     *
     * @param fmt the format string eg. robot_attack_%02d.png
     * @param count the total number of frames
     * @param fps frame per second
     */
    static Animation *createAnimation(const char *fmt, int count, float fps);
    
public:
    // actions
    CC_SYNTHESIZE_RETAIN(Action*, _idleAction, IdleAction);
    CC_SYNTHESIZE_RETAIN(Action*, _attackAction, AttackAction);
    CC_SYNTHESIZE_RETAIN(Action*, _walkAction, WalkAction);
    CC_SYNTHESIZE_RETAIN(Action*, _hurtAction, HurtAction);
    CC_SYNTHESIZE_RETAIN(Action*, _knockedOutAction, KnockedOutAction);
    
    
    // collision boxes
    CC_SYNTHESIZE(BoundingBox, _hitBox, HitBox);
    CC_SYNTHESIZE(BoundingBox, _attackBox, AttackBox);
    
    // states
    CC_SYNTHESIZE(ActionState, _actionState, ActionState);
    
    // attributes
    CC_SYNTHESIZE(float, _walkSpeed, WalkSpeed);
    CC_SYNTHESIZE(float, _hitPoints, HitPoints);
    CC_SYNTHESIZE(float, _damage, Damage);
    
    // movement
    CC_SYNTHESIZE(Point, _velocity, Velocity);
    CC_SYNTHESIZE(Point, _desiredPosition, DesiredPosition);
    
    // measurements
    CC_SYNTHESIZE(float, _centerToSides, CenterToSides);
    CC_SYNTHESIZE(float, _centerToBottom, CenterToBottom);
    
    // action methods
    void idle();
    void attack();
    void hurtWithDamage(float damage);
    void knockout();
    void walkWithDirection(Vec2 direction);

    // scheduled methods
    void update(float delta);
    
    // collision box factory method
    BoundingBox createBoundingBoxWithOrigin(Vec2 origin, Size size);
    
    void setPosition(Vec2 position);
};
#endif /* ActionSprite_h */
