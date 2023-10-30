//
// Created by Md. Faizul Islam on 30/10/23.
//

#ifndef PROJ_ANDROID_PARALLAXFOREGROUND_H
#define PROJ_ANDROID_PARALLAXFOREGROUND_H

#include "BackgroundContainer.h"

class ParallaxForeground : public BackgroundContainer {
    float mTileHeight = 50;
public:
    ~ParallaxForeground();

    ParallaxForeground();

    static ParallaxForeground* create(float deltaXFactor);

    virtual bool init(float deltaXFactor);

    virtual void addBackgrounds();
    void addTiles(Node* container);
    float getTileHeight();
    void addTrees(Node* container);
};

#endif //PROJ_ANDROID_PARALLAXFOREGROUND_H
