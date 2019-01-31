////
////  Hero.cpp
////  pompadroid
////
////  Created by Quang Vu on 1/24/19.
////
//
//#include "HeroOLD.h"
//
//bool HeroOLD::init()
//{
//    if(!ActionSprite::initWithSpriteFrameName("hero_idle_00.png"))
//    {
//        return false;
//    }
//
//    //idle animation
//    CallFunc *callbackIdle = CallFunc::create(std::bind(&Hero::idle, this));
//    
//    // IDLE
////    Animation *idleAnimation = [CCAnimation animationWithSpriteFrames:[idleFrames getNSArray] delay:1.0/12.0];
////    self.idleAction = [CCRepeatForever actionWithAction:[CCAnimate actionWithAnimation:idleAnimation]];
//    Animation* idleAnimation = createAnimation("hero_idle_%02d.png", 6, 12);
//    setIdleAction(RepeatForever::create(Animate::create(idleAnimation)));
//    
//    // ATTACK
////    CCArray *attackFrames = [CCArray arrayWithCapacity:3];
////    for (i = 0; i < 3; i++) {
////        CCSpriteFrame *frame = [[CCSpriteFrameCache sharedSpriteFrameCache] spriteFrameByName:[NSString stringWithFormat:@"hero_attack_00_%02d.png", i]];
////        [attackFrames addObject:frame];
////    }
////    CCAnimation *attackAnimation = [CCAnimation animationWithSpriteFrames:[attackFrames getNSArray] delay:1.0/24.0];
////    self.attackAction = [CCSequence actions:[CCAnimate actionWithAnimation:attackAnimation], [CCCallFunc actionWithTarget:self selector:@selector(idle)], nil];
//    Animation* attackAnimation = createAnimation("hero_attack_00_%02d.png", 3, 20);
//    setAttackAction(Sequence::create(Animate::create(attackAnimation), callbackIdle, NULL));
//    
//    // WALK
//    Animation *walkAnimation = createAnimation("hero_walk_%02d.png", 7, 14);
//    setWalkAction(RepeatForever::create(Animate::create(walkAnimation)));
//
//    _centerToBottom = 39.0;
//    _centerToSides = 29.0;
//    _hitPoints = 100.0;
//    _damage = 20.0;
//    _walkSpeed = 80;
//    
////    Animation *idle = createAnimation("hero_idle_%02d.png", 6, 12);
////    setIdleAction(RepeatForever::create(Animate::create(idle)));
////
////    Animation *walk = createAnimation("hero_walk_%02d.png", 7, 14);
////    setWalkAction(RepeatForever::create(Animate::create(walk)));
////
////    Animation *attack = createAnimation("hero_attack_00_%02d.png", 3, 20);
////    setAttackAction(Sequence::create(Animate::create(attack), callbackIdle, NULL));
////
////    Animation *hurt = createAnimation("hero_hurt_%02d.png", 3, 15);
////    setHurtAction(Sequence::create(Animate::create(hurt), callbackIdle, NULL));
////
////    Animation *knockout = createAnimation("hero_knockout_%02d.png", 5, 12);
////    setKnockoutAction(Sequence::create(Animate::create(knockout), NULL));
//    
//    return true;
//}
//
///**
// *
// */
//Vector<SpriteFrame *> HeroOLD::getAnimation(const char *format, int count, SpriteFrameCache* spritecache)
//{
//    Vector<SpriteFrame *> animFrames;
//    char str[100];
//    for(int i = 0; i < count; i++)
//    {
//        sprintf(str, format, i);
//        animFrames.pushBack(spritecache->getSpriteFrameByName(str));
//    }
//    return animFrames;
//}
