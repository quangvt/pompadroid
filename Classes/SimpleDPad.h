//
//  SimpleDPad.h
//  pompadroid
//
//  Created by Quang Vu on 1/25/19.
//

#ifndef SimpleDPad_h
#define SimpleDPad_h
#pragma once

#include "cocos2d.h"

USING_NS_CC;

class SimpleDPad;

// TODO: Review Code
// ref: https://blog.csdn.net/yejinxiong001/article/details/78663541
class SimpleDPadDelegate
{
public:
    virtual void didChangeDirectionTo(SimpleDPad *simpleDPad, Point direction) = 0;
    virtual void isHoldingDirection(SimpleDPad *simpleDPad, Point direction) = 0;
    virtual void simpleDPadTouchEnded(SimpleDPad *simpleDPad) = 0;
};

class SimpleDPad : public Sprite
{
    float _radius;
    Vec2 _direction;
//    void update(float delta);
public:
    // Create
    static SimpleDPad* dPadWithFile(const std::string& filename, float radius);
    bool initWithFile(const std::string& filename, float radius);
    CREATE_FUNC(SimpleDPad);

    // Touch (single)
    virtual bool onTouchBegan(Touch*, Event*);
    virtual void onTouchEnded(Touch*, Event*);
    virtual void onTouchMoved(Touch*, Event*);
    void updateDirectionForTouchLocation(Vec2 location);
    
    // Touch (multi)
//    virtual void onTouchesBegan(const std::vector<Touch*>& touches, Event* event);
//    virtual void onTouchMoved(const Touch* touch, Event* event);
//    virtual void onTouchEnded(const Touch* touch, Event* event);
//    void updateDirectionForTouchLocation(Vec2 location);
    
    // Properties
    CC_SYNTHESIZE(SimpleDPadDelegate*, _delegator, Delegator);
    CC_SYNTHESIZE(bool, _isHeld, IsHeld);
    
//    void onEnter();
//    void onEnterTransitionDidFinish();
//    void onExit();
//
    void update(float delta);
//    void onExitTransitionDidStart();
    
};

#endif /* SimpleDPad_h */
