//
// Created by Md. Faizul Islam on 30/10/23.
//

#ifndef PROJ_ANDROID_GAMECONTAINER_H
#define PROJ_ANDROID_GAMECONTAINER_H

#include "cocos2d.h"
#include "ParallaxBackground.h"
#include "ParallaxForeground.h"
#include "Character.h"

USING_NS_CC;
using namespace std;

class GameContainer : public Node{
    Character* mCharacter;
    ParallaxBackground* mBgBack;
    ParallaxBackground* mBgMid;
    ParallaxForeground* mBgFront;
public:
    ~GameContainer();
    GameContainer();

    static GameContainer *create();
    virtual bool init();

    void addParallaxBackgrounds();
    void addParallaxForeground();
    void addCharacter();
};


#endif //PROJ_ANDROID_GAMECONTAINER_H
