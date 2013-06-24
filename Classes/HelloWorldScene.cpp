#include "HelloWorldScene.h"
#include "AppMacros.h"
USING_NS_CC;


CCScene* HelloWorld::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    HelloWorld *layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
this->setTouchEnabled(true);
this->schedule( schedule_selector(HelloWorld::update) );  
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
	CCSprite* pImage = CCSprite::create("bird.png");
	this->addChild(pImage,2,kBird);
	moveSprite();
	//putTank();

	CCSprite* pTank = CCSprite::create("tower.png");
	pTank->setPosition(ccp(100,200));
	this->addChild(pTank,2,kTank);
//	checkCollision();
	
	
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                        "CloseNormal.png",
                                        "CloseSelected.png",
                                        this,
                                        menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));

    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label
    
    CCLabelTTF* pLabel = CCLabelTTF::create("Hello World", "Arial", TITLE_FONT_SIZE);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));

    // add the label as a child to this layer
    this->addChild(pLabel, 1);

    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");

    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));

    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);
	
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}



void HelloWorld::handleUserTouch(CCTouch *touch)
{
	CCPoint location = touch->getLocation();
	location = CCDirector::sharedDirector()->convertToGL(location);
//	pImage->setPosition(ccp(location.x,location.y));
	
	CCLOG("%d",location.x);
	CCLOG("%d",location.y);
	CCSprite *pImage = (CCSprite*)getChildByTag(kBird);
	pImage->setPosition(location);
}

void HelloWorld::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    // get the touch object
    CCTouch* touch = (CCTouch *)touches->anyObject();
    this->handleUserTouch(touch);
}



void HelloWorld::moveSprite(void)
{
	
	CCSprite *pImage = (CCSprite*)getChildByTag(kBird);
	bird_pos.x = (float) CCDirector::sharedDirector()->getWinSize().width/2;
        bird_pos.y = (float) CCDirector::sharedDirector()->getWinSize().width/2;
        pImage->setPosition(bird_pos);
}


//
//void HelloWorld::putTank(void)
//{
//	CCSprite *pTank = (CCSprite*)getChildByTag(kTank);
//
//}

void HelloWorld::update(float dt)
{
	CCSprite *pImage = (CCSprite*)getChildByTag(kBird);
	CCSprite *pTank = (CCSprite*)getChildByTag(kTank);
	CCRect playerRect   = CCRectMake(pImage->getPositionX(),pImage->getPositionY(),6,1);
	CCRect tankRect		= CCRectMake(pTank->getPositionX(),pImage->getPositionY(),6,1);
	
if(playerRect.intersectsRect(tankRect))
{
     CCLog ("Hallalua");
}
else
{
	CCLog("Not Intersected");
}
}


//void HelloWorld::checkCollision(void)
//{
//	CCSprite *pImage = (CCSprite*)getChildByTag(kBird);
//	CCSprite *pTank = (CCSprite*)getChildByTag(kTank);
//	
//
//	CCRect playerRect   = CCRectMake(pImage->getPositionX(),pImage->getPositionY(),57,57);
//	CCRect tankRect		= CCRectMake(pTank->getPositionX(),pImage->getPositionY(),84,84);
//	
//if(playerRect.intersectsRect(tankRect))
//{
//     CCLog ("Hallalua");
//}
//else
//{
//	CCLog("Not Intersected");
//}
//}