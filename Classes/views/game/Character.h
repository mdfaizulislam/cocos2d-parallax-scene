//
// Created by Md. Faizul Islam on 30/10/23.
//

#ifndef PROJ_ANDROID_CHARACTER_H
#define PROJ_ANDROID_CHARACTER_H

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class Character: public Node{
bool mIsJumping = false;
Sprite* mImage = nullptr;
public:
    ~Character();
    Character();

    static Character* create();

    virtual bool init();
    void addJumperImage();
    void adjustCharacterContentSize();

    virtual void onEnterTransitionDidFinish();
    virtual void onExitTransitionDidStart();

    void doJump(Ref* obj);
    void onJumpComplete();
};


#endif //PROJ_ANDROID_CHARACTER_H
