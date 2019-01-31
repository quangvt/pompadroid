//
//  Defines.h
//  pompadroid
//
//  Created by Quang Vu on 1/24/19.
//

#ifndef Defines_h
#define Defines_h

#include "cocos2d.h"

USING_NS_CC;

////convenience measurements
//#define SCREEN Director::getInstance()->getVisibleSize()
//#define CENTER Vec2(SCREEN.width/2, SCREEN.height/2)
//#define CURTIME CACurrentMediaTime()
//
////convenience functions
//#define random_range(low,high) (arc4random()%(high-low+1))+low
//#define frandom (float)arc4random()/UINT64_C(0x100000000)
//#define frandom_range(low,high) ((high-low)*frandom)+low

//enumerations
typedef enum {
    ACTION_STATE_NONE = 0,
    ACTION_STATE_IDLE,
    ACTION_STATE_WALK,
    ACTION_STATE_ATTACK,
    ACTION_STATE_HURT,
    ACTION_STATE_KNOCKOUT,
} ActionState;

//structures
typedef struct
{
    Rect actual;
    Rect original;
} BoundingBox;

#endif /* Defines_h */
