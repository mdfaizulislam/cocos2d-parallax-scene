//
// Created by Md. Faizul Islam on 30/10/23.
//

#include "ParallaxBackground.h"

ParallaxBackground::~ParallaxBackground() {

}

ParallaxBackground::ParallaxBackground() {

}

ParallaxBackground* ParallaxBackground::create(float deltaXFactor, BgLayerIndex layerId) {
    ParallaxBackground* ret = new ParallaxBackground();
    if(ret && ret->init(deltaXFactor, layerId)) {
        return ret;
    } else {
        delete ret;
        ret = nullptr;
        return nullptr;
    }
}

bool ParallaxBackground::init(float deltaXFactor, BgLayerIndex layerId) {
    if(BackgroundContainer::init(deltaXFactor))
    {
        this->layerIndex = layerId;
        this->addBackgrounds();

        // update self content size according to bg size
        this->setContentSize(this->mBg1->getContentSize());
        return true;
    }
    return false;
}

void ParallaxBackground::addBackgrounds() {
    if (this->layerIndex == BgLayerIndex::back) {
        this->mBg1 = Sprite::create("bgBack.png");
        this->mBg2= Sprite::create("bgBack.png");
    } else if (this->layerIndex == BgLayerIndex::mid){
        this->mBg1 = Sprite::create("bgMid.png");
        this->mBg2 = Sprite::create("bgMid.png");
    }

    this->mBg1->setScaleY(Director::getInstance()->getWinSize().height/this->mBg1->getContentSize().height);
    this->mBg2->setScaleY(Director::getInstance()->getWinSize().height/this->mBg2->getContentSize().height);

    this->addChild(this->mBg1, 0);
    this->addChild(this->mBg2, 0);

    // update mBg2 position X which will help on scrolling background functionality
    this->mBg2->setPositionX(this->mBg1->getContentSize().width);

}