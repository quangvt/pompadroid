//
//  Hero.h
//  pompadroid
//
//  Created by Quang Vu on 1/28/19.
//

#ifndef Hero_h
#define Hero_h

#include "SimpleAudioEngine.h"
#import "cocos2d.h"
#import "ActionSprite.h"

USING_NS_CC;

class Hero : public ActionSprite
{
    Vector<SpriteFrame *> getAnimation(const char *format, int count, SpriteFrameCache* spritecache);
public:
    bool init();
    CREATE_FUNC(Hero);
    void knockout();
};

#endif /* Hero_h */
