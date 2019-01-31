//
//  Hero.cpp
//  pompadroid
//
//  Created by Quang Vu on 1/28/19.
//

#include "Hero.h"

bool Hero::init()
{
    if(!ActionSprite::initWithSpriteFrameName("hero_idle_00.png"))
    {
        return false;
    }

    // IDLE
    Animation* idleAnimation = createAnimation("hero_idle_%02d.png", 6, 12);
    setIdleAction(RepeatForever::create(Animate::create(idleAnimation)));
    
    // ATTACK
    CallFunc *callbackIdle = CallFunc::create(std::bind(&Hero::idle, this));
    Animation* attackAnimation = createAnimation("hero_attack_00_%02d.png", 3, 24);
    setAttackAction(Sequence::create(Animate::create(attackAnimation), callbackIdle, NULL));
    
    // WALK
    Animation *walkAnimation = createAnimation("hero_walk_%02d.png", 8, 12);
    setWalkAction(RepeatForever::create(Animate::create(walkAnimation)));
    
    // HURT
    Animation *hurtAnimation = createAnimation("hero_hurt_%02d.png", 3, 12);
    setHurtAction(Sequence::create(Animate::create(hurtAnimation), callbackIdle, NULL));
    
    // KNOCKOUT
    Animation *knockedOutAnimation = createAnimation("hero_knockout_%02d.png", 5, 12);
    setKnockedOutAction(Sequence::create(Animate::create(knockedOutAnimation), Blink::create(2.0, 10.0), NULL));
    
    _centerToBottom = 39.0;
    _centerToSides = 29.0;
    _hitPoints = 100.0;
    _damage = 20.0;
    _walkSpeed = 80;
    
    _hitBox = createBoundingBoxWithOrigin(Vec2(-_centerToSides, -_centerToBottom), Size(_centerToSides*2, _centerToBottom*2));
    _attackBox = createBoundingBoxWithOrigin(Vec2(_centerToSides, -10), Size(20, 20));
    
    return true;
}

void Hero::knockout() {
    ActionSprite::knockout();
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sounds/pd_herodeath.caf");
}
