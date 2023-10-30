//
// Created by Md. Faizul Islam on 30/10/23.
//

#ifndef PROJ_ANDROID_BACKGROUNDCONTAINER_H
#define PROJ_ANDROID_BACKGROUNDCONTAINER_H

#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class BackgroundContainer : public Node{

protected:
    Node* mBg1;
    Node* mBg2;
    float mDeltaXFactor = 1.0;
public:
    ~BackgroundContainer();
    BackgroundContainer();

    static BackgroundContainer* create(float deltaXFactor);

    virtual bool init(float deltaXFactor);
    virtual void addBackgrounds();
    virtual void onEnterTransitionDidFinish();
    virtual void onExitTransitionDidStart();

    void onCharacterJump(Ref* obj);
    void moveBackgrounds(Node* node);
    void update(float  dt);
};


#endif //PROJ_ANDROID_BACKGROUNDCONTAINER_H
