//
//  GameScene.h
//  pompadroid
//
//  Created by Quang Vu on 1/24/19.
//

#ifndef GameScene_h
#define GameScene_h

#include "cocos2d.h"
#include "GameLayer.h"
#include "HudLayer.h"

USING_NS_CC;

/**
 @brief    Game scene of game.
 @return Scene
 */
class GameScene : public Scene
{
public:
    static Scene* createScene();
    
    CC_SYNTHESIZE(GameLayer*, _gameLayer, GameLayer);
    CC_SYNTHESIZE(HudLayer*, _hudLayer, HudLayer);
};

#endif /* GameScene_h */
