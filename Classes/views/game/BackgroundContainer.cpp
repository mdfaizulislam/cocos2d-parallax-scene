//
// Created by Md. Faizul Islam on 30/10/23.
//

#include "../../Constants.h"
#include "../../configs/Config.h"
#include "BackgroundContainer.h"


BackgroundContainer::~BackgroundContainer() {

}

BackgroundContainer::BackgroundContainer() {

}

BackgroundContainer* BackgroundContainer::create(float deltaXFactor) {
    BackgroundContainer* ret = new BackgroundContainer();
    if(ret && ret->init(deltaXFactor)) {
        return ret;
    } else {
        delete ret;
        ret = nullptr;
        return nullptr;
    }
}

bool BackgroundContainer::init(float deltaXFactor) {
    if(Node::init())
    {
        this->mDeltaXFactor = deltaXFactor;
        return true;
    }
    return false;
}

void BackgroundContainer::addBackgrounds() {

}

void BackgroundContainer::onEnterTransitionDidFinish() {
    Node::onEnterTransitionDidFinish();
    NotificationCenter::getInstance()->addObserver(this, callfuncO_selector(BackgroundContainer::onCharacterJump), Events::EVENT_JUMP, NULL);
    this->scheduleUpdate();
}

void BackgroundContainer::onExitTransitionDidStart() {
    Node::onExitTransitionDidStart();
    NotificationCenter::getInstance()->removeObserver(this, Events::EVENT_JUMP);
    this->unscheduleUpdate();
}

void BackgroundContainer::onCharacterJump(Ref* obj) {
    // on character jump, move all backgrounds towards left
    this->moveBackgrounds(this->mBg1);
    this->moveBackgrounds(this->mBg2);
}

void BackgroundContainer::moveBackgrounds(Node* node){
    float moveX = JumpConfig::bgMoveX;
    moveX = moveX / this->mDeltaXFactor;
    node->runAction(MoveBy::create(JumpConfig::duration, Vec2(moveX, 0)));
}

void BackgroundContainer::update(float  dt){

    // update positions so that bgs will look like scrolling backgrounds
    // which will help us to create parallax scene

    if ( this->mBg1->getPositionX() < - this->getContentSize().width ) {
        this->mBg1->setPositionX(this->mBg2->getPositionX() +
            this->getContentSize().width);
    }

    if ( this->mBg2->getPositionX() < - this->getContentSize().width ) {
        this->mBg2->setPositionX( this->mBg1->getPositionX() +
            this->getContentSize().width);
    }
}