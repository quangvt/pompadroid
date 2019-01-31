//
//  IntroLayer.h
//  pompadroid
//
//  Created by Quang Vu on 1/24/19.
//

#ifndef IntroLayer_h
#define IntroLayer_h

#include "cocos2d.h"

USING_NS_CC;

class IntroLayer : public Layer
{
    void onEnter();
    void makeTransition(float delta);
public:
    virtual bool init();
    
    static Scene* createScene();
    
    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(IntroLayer);
};

#endif /* IntroLayer_h */
