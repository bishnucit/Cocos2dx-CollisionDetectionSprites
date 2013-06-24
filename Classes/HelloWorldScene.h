#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayer
{
public:
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
	void moveSprite(void);
	void putTank(void);
	cocos2d::CCPoint bird_pos;
	cocos2d::CCPoint tank_pos;
	void checkCollision(void);
	void update(float dt);
	//cocos2d::CCMenuItemImage *pImage;
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::CCScene* scene();
    
    // a selector callback
    void menuCloseCallback(CCObject* pSender);
  void handleUserTouch(cocos2d::CCTouch *touch);
 void  ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    // implement the "static node()" method manually
    CREATE_FUNC(HelloWorld);
	enum
	{
		kBird = 1,
		kTank = 2
	};

	
};

#endif // __HELLOWORLD_SCENE_H__
