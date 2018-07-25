#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


float HelloWorld::getScaleValueSpriteX(Sprite *s, float x)
{
    float visSizeX = Director::getInstance()->getVisibleSize().width;
    float spriteWidth = s->getContentSize().width;
    float targetSmallSquareWidth = visSizeX * x;
    float scaleFactorX = targetSmallSquareWidth / spriteWidth;
    
    return scaleFactorX;
}

float HelloWorld::getScaleValueSpriteY(Sprite *s, float y)
{
    float visSizeY = Director::getInstance()->getVisibleSize().height;
    float spriteHeight = s->getContentSize().height;
    float targetSmallSquareHeight = visSizeY * y;
    float scaleFactorY = targetSmallSquareHeight / spriteHeight;
    
    return scaleFactorY;
}




// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    Sprite *bgGame = Sprite::create("gameBackground.png");
    bgGame->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height/2);
    bgGame->setScaleX(getScaleValueSpriteX(bgGame, 1.0f));
    bgGame->setScaleY(getScaleValueSpriteY(bgGame, 1.0f));
    this->addChild(bgGame);

    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);


}
