//
//  ActionSprite.cpp
//  pompadroid
//
//  Created by Quang Vu on 1/28/19.
//

#include "ActionSprite.h"

void ActionSprite::idle()
{
    if (_actionState != ACTION_STATE_IDLE)
    {
        this->stopAllActions();
        this->runAction(_idleAction);
        _actionState = ACTION_STATE_IDLE;
        _velocity = Point::ZERO;
    }
}

void ActionSprite::walkWithDirection(Vec2 direction)
{
    if (_actionState == ACTION_STATE_IDLE)
    {
        this->stopAllActions();
        this->runAction(_walkAction);
        _actionState = ACTION_STATE_WALK;
    }
    if (_actionState == ACTION_STATE_WALK)
    {
        _velocity = Vec2(direction.x * _walkSpeed, direction.y * _walkSpeed);
        if (_velocity.x >= 0)
        {
            this->setScaleX(1.0);
        }
        else
        {
            this->setScaleX(-1.0);
        }
    }
}

void ActionSprite::attack()
{
    if (_actionState == ACTION_STATE_IDLE ||
        _actionState == ACTION_STATE_ATTACK ||
        _actionState == ACTION_STATE_WALK)
    {
        this->stopAllActions();
        this->runAction(_attackAction);
        _actionState = ACTION_STATE_ATTACK;
    }
}

void ActionSprite::hurtWithDamage(float damage)
{
    if (_actionState != ACTION_STATE_KNOCKOUT)
    {
        this->stopAllActions();
        this->runAction(_hurtAction);
        _actionState = ACTION_STATE_HURT;
        _hitPoints -= damage;
        
        // sound
        int randomSound = rand() % 2;
        std::string randomSoundString = StringUtils::format("Sounds/pd_hit%d.caf", randomSound);
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(randomSoundString.c_str());
        
        if (_hitPoints <= 0.0)
        {
            this->knockout();
        }
    }
}

void ActionSprite::knockout()
{
    this->stopAllActions();
    this->runAction(_knockedOutAction);
    _hitPoints = 0.0;
    _actionState = ACTION_STATE_KNOCKOUT;
}

void ActionSprite::update(float delta)
{
    if (_actionState == ACTION_STATE_WALK)
    {
        _desiredPosition = _position + _velocity*delta;
    }
}

Animation *ActionSprite::createAnimation(const char *fmt, int count, float fps)
{
    auto frames = new Vector<SpriteFrame*>(count);
    char str[100];
    for (int i = 0; i < count; i++) {
        sprintf(str, fmt, i);
        SpriteFrame *frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(str);
        frames->pushBack(frame);
    }
    return Animation::createWithSpriteFrames(*frames, 1 / fps);
}

BoundingBox ActionSprite::createBoundingBoxWithOrigin(Vec2 origin, Size size)
{
    BoundingBox boundingBox;
    boundingBox.original.origin = origin;
    boundingBox.original.size = size;
    boundingBox.actual.origin = this->getPosition() + origin;
    boundingBox.actual.size = size;
    return boundingBox;
}

void ActionSprite::transformBoxes()
{
//    _hitBox.actual.origin = getPosition() + Vec2(_hitBox.original.origin.x * getScaleX(),
//                                                 _hitBox.original.origin.y * getScaleY());
//    _hitBox.actual.size = Size(_hitBox.original.size.width * getScaleX(),
//                               _hitBox.original.size.height * getScaleY());
//    _attackBox.actual.origin = getPosition() + Vec2(_attackBox.original.origin.x * getScaleX(),
//                                                    _attackBox.original.origin.y * getScaleY());
//    _attackBox.actual.size = Size(_attackBox.original.size.width * getScaleX(),
//                                  _attackBox.original.size.height * getScaleY());
    if (getScaleX() >= 0)
    {
        _hitBox.actual.origin = getPosition() + Vec2(_hitBox.original.origin.x * getScaleX(),
                                                     _hitBox.original.origin.y);
        _hitBox.actual.size = Size(_hitBox.original.size.width, _hitBox.original.size.height);
        _attackBox.actual.origin = getPosition() + Vec2(_attackBox.original.origin.x * getScaleX(), _attackBox.original.origin.y);
        _attackBox.actual.size = Size(_attackBox.original.size.width, _attackBox.original.size.height);
    } else {
        _hitBox.actual.origin = getPosition() + Vec2((_hitBox.original.origin.x + _hitBox.original.size.width) * getScaleX(), _hitBox.original.origin.y);
        _hitBox.actual.size = Size(_hitBox.original.size.width, _hitBox.original.size.height);
        _attackBox.actual.origin = getPosition() + Vec2((_attackBox.original.origin.x + _attackBox.original.size.width) * getScaleX(), _attackBox.original.origin.y);
        _attackBox.actual.size = Size(_attackBox.original.size.width, _attackBox.original.size.height);
    }
}

void ActionSprite::setPosition(Vec2 position)
{
    Sprite::setPosition(position);
    this->transformBoxes();
}
