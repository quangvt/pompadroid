//
//  HudLayer.cpp
//  pompadroid
//
//  Created by Quang Vu on 1/24/19.
//

#include "HudLayer.h"

bool HudLayer::init()
{
    if (!Layer::init())
    {
        return false;
    }
    
    _dPad = SimpleDPad::dPadWithFile("Sprites/pd_dpad.png", 64.0);
    _dPad->setPosition(Vec2(64.0, 64.0));
    _dPad->setContentSize(Size(128.0, 128.0));
    _dPad->setOpacity(100.0);
    this->addChild(_dPad);
    
//    _rdPad = SimpleDPad::dPadWithFile("Sprites/pd_dpad.png", 64.0);
//    _rdPad->setPosition(Vec2(visibleSize.width - 64.0, 64.0));
//    _rdPad->setOpacity(100.0);
//    this->addChild(_rdPad);
    
    return true;
}
