//
//  HudLayer.h
//  pompadroid
//
//  Created by Quang Vu on 1/24/19.
//

#ifndef HudLayer_h
#define HudLayer_h

#include "cocos2d.h"
#include "SimpleDPad.h"

USING_NS_CC;

class HudLayer : public Layer
{
public:
    virtual bool init();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(HudLayer);
    
    CC_SYNTHESIZE(SimpleDPad*, _dPad, DPad);
    CC_SYNTHESIZE(SimpleDPad*, _rdPad, RdPad);
};

#endif /* HudLayer_h */
