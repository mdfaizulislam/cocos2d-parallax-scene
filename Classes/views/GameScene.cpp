/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

 http://www.cocos2d-x.org

 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:

 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#include "GameScene.h"
#include "SimpleAudioEngine.h"
#include "../Constants.h"

USING_NS_CC;

Scene *GameScene::createScene()
{
    return GameScene::create();
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    // 1. super init first
    if (!Scene::init())
    {
        return false;
    }

    // add simple bg layer color
    auto bg = LayerColor::create(Color4B(53, 53, 53, 255));
    this->addChild(bg, 0);

    // add game container
    this->addGameContainer();

    // add UI jump button
    this->addJumpButton();

    return true;
}

void GameScene::addGameContainer() {
    this->mGameContainer = GameContainer::create();
    this->addChild(this->mGameContainer, 1);
}

void GameScene::addJumpButton() {
    auto winSize = Director::getInstance()->getWinSize();

    auto buttonJump = MenuItemImage::create("button.png", "button_pressed.png", "button.png",
                                            CC_CALLBACK_1(GameScene::onJumpPressed, this));

    float x = winSize.width - buttonJump->getContentSize().width / 2 - 20;
    float y = buttonJump->getContentSize().height / 2 + 20;
    buttonJump->setPosition(Vec2(x, y));

    // add the label "Jump" as a child to this button
    auto label = Label::createWithTTF("Jump", "fonts/Font.ttf", 40);
    label->setPosition(Vec2(buttonJump->getContentSize().width / 2,buttonJump->getContentSize().height/2));
    buttonJump->addChild(label, 1);

    // create menu
    auto menu = Menu::create(buttonJump, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 2);
}

void GameScene::onJumpPressed(Ref *pSender)
{
    // trigger notification on jump button press
    NotificationCenter::getInstance()->postNotification(Events::EVENT_JUMP);
}
