//
// Created by Md. Faizul Islam on 30/10/23.
//

#include "Character.h"
#include "../../configs/Config.h"
#include "../../Constants.h"

Character::~Character() {

}

Character::Character() {

}

Character* Character::create() {
    Character* ret = new Character();
    if(ret && ret->init()) {
        return ret;
    } else {
        delete ret;
        ret = nullptr;
        return nullptr;
    }
}

bool Character::init() {
    if(Node::init())
    {
        this->addJumperImage();
        this->adjustCharacterContentSize();
        return true;
    }
    return false;
}

void Character::addJumperImage() {
    this->mImage = Sprite::create("character.png");
    this->addChild(this->mImage, 1);
}
void Character::adjustCharacterContentSize() {
    this->setContentSize(this->mImage->getContentSize());
}

void Character::onEnterTransitionDidFinish() {
    Node::onEnterTransitionDidFinish();
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(Character::doJump), Events::EVENT_JUMP, NULL);
}

void Character::onExitTransitionDidStart() {
    Node::onExitTransitionDidStart();
    NotificationCenter::getInstance()->removeObserver(this, Events::EVENT_JUMP);
}

void Character::doJump(Ref* obj) {
    if (this->mIsJumping) return;

    this->mIsJumping = true;
    this->runAction(Sequence::create(
            JumpBy::create(JumpConfig::duration, Vec2(0, 0), JumpConfig::jumpHeight, 1),
                    CallFunc::create(CC_CALLBACK_0(Character::onJumpComplete, this)),
                    NULL)
            );
}

void Character::onJumpComplete() {
    this->mIsJumping = false;
}