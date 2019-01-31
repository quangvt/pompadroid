//
//  GameScene.cpp
//  pompadroid
//
//  Created by Quang Vu on 1/24/19.
//

#include "GameScene.h"

Scene* GameScene::createScene()
{
    GameScene* scene = new GameScene();
    
    GameLayer* gameLayer = GameLayer::create();
    scene->_gameLayer = gameLayer;
    scene->addChild(scene->_gameLayer, 0);
    
    HudLayer* hudLayer = HudLayer::create();
    scene->_hudLayer = hudLayer;
    scene->addChild(scene->_hudLayer, 1);
    
    scene->_hudLayer->getDPad()->setDelegator(scene->_gameLayer);
    scene->_gameLayer->setHUD(scene->_hudLayer);
    
    return scene;
}

//bool GameScene::init()
//{
//    if (!Scene::init())
//    {
//        return false;
//    }
//
//    _gameLayer = GameLayer::create();
//    this->addChild(_gameLayer, 0);
//    _hudLayer = HudLayer::create();
//    this->addChild(_hudLayer, 1);
//
//    return true;
//}
