//
// Created by Md. Faizul Islam on 30/10/23.
//

#include "GameContainer.h"
#include "../../configs/Config.h"

GameContainer::~GameContainer() {

}

GameContainer::GameContainer() {

}

GameContainer* GameContainer::create() {
    GameContainer* ret = new GameContainer();
    if(ret && ret->init()) {
        return ret;
    } else {
        delete ret;
        ret = nullptr;
        return nullptr;
    }
}

bool GameContainer::init() {
    if(Node::init())
    {
        this->addParallaxBackgrounds();
        this->addParallaxForeground();
        this->addCharacter();
        return true;
    }
    return false;
}

void GameContainer::addParallaxBackgrounds() {
    auto winSize = Director::getInstance()->getWinSize();

    this->mBgBack = ParallaxBackground::create(JumpConfig::deltaXScaleFactorBack, BgLayerIndex::back);
    this->mBgBack->setPosition(winSize.width / 2, winSize.height / 2);
    this->addChild(this->mBgBack, 0);

    this->mBgMid = ParallaxBackground::create(JumpConfig::deltaXScaleFactorMid, BgLayerIndex::mid);
    this->mBgMid->setPosition(winSize.width / 2, winSize.height / 2);
    this->addChild(this->mBgMid, 1);
}

void GameContainer::addParallaxForeground() {
    this->mBgFront = ParallaxForeground::create(JumpConfig::deltaXScaleFactorFront);
    this->addChild(this->mBgFront, 3);
}

void GameContainer::addCharacter() {
    this->mCharacter = Character::create();
    this->mCharacter->setScale(0.5);
    this->mCharacter->setPositionX(this->mCharacter->getScaleX() * this->mCharacter->getContentSize().width/2 + 35);
    this->mCharacter->setPositionY(this->mCharacter->getScaleY() * this->mCharacter->getContentSize().height/2 + this->mBgFront->getTileHeight());
    this->addChild(this->mCharacter, 2);
}