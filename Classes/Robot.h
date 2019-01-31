//
//  Robot.h
//  pompadroid
//
//  Created by Quang Vu on 1/28/19.
//

#ifndef Robot_h
#define Robot_h

#include "SimpleAudioEngine.h"
#include "ActionSprite.h"

class Robot : public ActionSprite
{
public:
    bool init() override;
    CREATE_FUNC(Robot);
    
    CC_SYNTHESIZE(long, _nextDecisionTime, NextDecisionTime);
    void knockout();
};

#endif /* Robot_h */
