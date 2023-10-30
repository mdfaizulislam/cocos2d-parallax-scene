//
// Created by Md. Faizul Islam on 30/10/23.
//

#include "ParallaxForeground.h"

ParallaxForeground::~ParallaxForeground() {

}

ParallaxForeground::ParallaxForeground() {

}

ParallaxForeground* ParallaxForeground::create(float deltaXFactor) {
    ParallaxForeground* ret = new ParallaxForeground();
    if(ret && ret->init(deltaXFactor)) {
        return ret;
    } else {
        delete ret;
        ret = nullptr;
        return nullptr;
    }
}

bool ParallaxForeground::init(float deltaXFactor) {
    if(BackgroundContainer::init(deltaXFactor))
    {
        // set self size
        this->setContentSize(Size(1920, Director::getInstance()->getWinSize().height));

        this->addBackgrounds();

        this->addTiles(this->mBg1);
        this->addTiles(this->mBg2);

        this->addTrees(this->mBg1);
        this->addTrees(this->mBg2);
        return true;
    }
    return false;
}

void ParallaxForeground::addBackgrounds() {

    auto tileHeight = Sprite::create("tile.png")->getContentSize().height;

    // add layer colors as backgrounds
    this->mBg1 = LayerColor::create(Color4B::YELLOW, this->getContentSize().width, tileHeight);
    this->mBg2 = LayerColor::create(Color4B::RED, this->getContentSize().width, tileHeight);

    this->addChild(this->mBg1, 1);
    this->addChild(this->mBg2, 1);

    // update mBg2 position X which will help on scrolling background functionality
    this->mBg2->setPositionX(this->mBg1->getContentSize().width);
}

void ParallaxForeground::addTiles(Node* container) {
    auto tileTemp = Sprite::create("tile.png");
    tileTemp->setAnchorPoint(Vec2(0.0,0.0));

    // store tile height, will be used for positioning in game container
    this->mTileHeight = tileTemp->getContentSize().height;

    // create and add tile
    auto tile = Sprite::create("tile.png", Rect(0, 0, this->getContentSize().width, tileTemp->getContentSize().height));
    tile->setAnchorPoint(Vec2(0.0,0.0));

    // update texture
    Texture2D::TexParams params = {GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT};
    tile->getTexture()->setTexParameters(&params);

    container->addChild(tile, 1);
}

float ParallaxForeground::getTileHeight() {
    return this->mTileHeight;
}

void ParallaxForeground::addTrees(Node* container) {
    auto treeCount = RandomHelper::random_int(5, 10);
    auto startPX = 0.05 * this->getContentSize().width;
    auto endPX = 0.95 * this->getContentSize().width;

    for (uint i = 0; i < treeCount; i += 1) {
        auto tree = Sprite::create("tree.png");
        tree->setAnchorPoint(Vec2(0.0, 0.0));
        auto scale = RandomHelper::random_real(0.65, 1.25);
        tree->setPositionX(RandomHelper::random_int(startPX, endPX));
        tree->setPositionY(-container->getContentSize().height/2);
        tree->setScale(scale);

        container->addChild(tree, 1);
    }
}