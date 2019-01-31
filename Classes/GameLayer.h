//
//  GameLayer.h
//  pompadroid
//
//  Created by Quang Vu on 1/24/19.
//

#ifndef GameLayer_h
#define GameLayer_h

#include "SimpleAudioEngine.h"
#include "cocos2d.h"
#include "Hero.h"
#include "Robot.h"
#include "SimpleDPad.h"
#include "HudLayer.h"

USING_NS_CC;

class GameLayer : public cocos2d::Layer, public SimpleDPadDelegate
{
    // Attributes
    /**
     * The tilemap of layer
     */
    TMXTiledMap* _map;
    
    /**
     *  Actors on GameLayer
     *      hero (main character)
     *      robots (enemies)
     */
    SpriteBatchNode* _actors;
    
    /**
     *  Hero (main character) of GameLayer
     */
    Hero* _hero;
    
    /**
     * Initilize Hero
     */
    void initHero();
    
    /**
     * Initilize Robots
     */
    void initRobots();
    
    /**
     * Update Hero's position by the desired position (Moving sprite)
     *
     * X = MIN( MapSizeWithInPixel - Hero's CenterToSides,          // Right Edge
     *          MAX(Hero's CenterToSides, Hero's DesiredPosition X))    // Left Edge & Middle
     *
     * Y = MIN( 3 * MapTileSizeHeight + Hero's CenterToBottom,          // Top Edge
     *          MAX(Hero's CenterToBottom, Hero's DesiredPosition Y));  // Bottom & Middle Edge
     */
    void updatePositions();
    
    /**
     * Centralize screen by Hero's position
     *
     * @param position is the current hero's position
     */
    void setViewpointCenter(Vec2 position);
    
    /**
     * Reorder all child in actors (hero and robots)
     * Lower y value, Higher z-order value
     */
    void reorderActors();
    
    /**
     *
     */
    void updateRobots(float delta);
    
    /**
     *
     */
    void endGame();
    
    /**
     *
     */
    void restartGame();
public:
    // Create object
    bool init() override;
    CREATE_FUNC(GameLayer);
    
    // Protocol
    void didChangeDirectionTo(SimpleDPad *simpleDPad, Point direction) override;
    void isHoldingDirection(SimpleDPad *simpleDPad, Point direction) override;
    void simpleDPadTouchEnded(SimpleDPad *simpleDPad) override;
    
    // Touch
    void onTouchesBegan(const std::vector<Touch*>& touches, Event *event) override;
    
    // Properties
    CC_SYNTHESIZE(HudLayer*, _hUD, HUD);
    CC_SYNTHESIZE(Vector<Robot*>*, _robots, Robots);
    
    void update(float delta) override;
};

#endif /* GameLayer_h */
