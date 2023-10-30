//
// Created by Md. Faizul Islam on 30/10/23.
//

#ifndef PROJ_ANDROID_PARALLAXBACKGROUND_H
#define PROJ_ANDROID_PARALLAXBACKGROUND_H

#include "BackgroundContainer.h"
#include "../../Constants.h"

class ParallaxBackground : public BackgroundContainer {
    BgLayerIndex layerIndex;
public:
    ~ParallaxBackground();

    ParallaxBackground();

    static ParallaxBackground* create(float deltaXFactor, BgLayerIndex layerId);

    virtual bool init(float deltaXFactor, BgLayerIndex layerId);

    virtual void addBackgrounds();
};

#endif //PROJ_ANDROID_PARALLAXBACKGROUND_H
