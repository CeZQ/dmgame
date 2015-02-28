#include "HelloWorldScene.h"

//#include "GameBackgroundView.h"


#include "TextUTF8.h"

#include "DMGameControl.h"

#include "PlayerSprite.h"


#include "SelectLevelView.h"

#include "KeyMessages.h"


USING_NS_CC;

const char* gb23122utf8(const char* gb2312)
{
	int len = MultiByteToWideChar(0, 0, gb2312, -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len + 1];
	memset(wstr, 0, len + 1);
	MultiByteToWideChar(0, 0, gb2312, -1, wstr, len);
	len = WideCharToMultiByte(65001, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* str = new char[len + 1];
	memset(str, 0, len + 1);
	WideCharToMultiByte(65001, 0, wstr, -1, str, len, NULL, NULL);
	if (wstr) delete[] wstr;
	return str;
}

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("MainImage.png");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);
	

	float x = 500, y = 320;


	auto label1 = LabelTTF::create(TextUTF8::getCStringForKey("kaishiyouxi"), "Marker Felt", 32);
//	label1->setHorizontalAlignment(TextHAlignment::CENTER);
	label1->setColor(Color3B::BLACK);
	auto startItem = MenuItemLabel::create(label1, CC_CALLBACK_1(HelloWorld::StartTheGame, this));
	startItem->setPosition(Vec2(x, y + 160));


	// 存档
	auto label2 = LabelTTF::create(TextUTF8::getCStringForKey("cundang"), "Marker Felt", 32);
//	label2->setHorizontalAlignment(TextHAlignment::CENTER);
	label2->setColor(Color3B::BLACK);
	auto cundangItem = MenuItemLabel::create(label2, CC_CALLBACK_1(HelloWorld::ReadArchive, this));
	cundangItem->setPosition(Vec2(x, y + 120));


	// 排名
	auto label3 = LabelTTF::create(TextUTF8::getCStringForKey("paiming"), "Marker Felt", 32);
//	label3->setHorizontalAlignment(TextHAlignment::CENTER);
	label3->setColor(Color3B::BLACK);
	auto paimingItem = MenuItemLabel::create(label3, CC_CALLBACK_1(HelloWorld::ReadArchive, this));
	paimingItem->setPosition(Vec2(x, y + 80));



	// 设置
	auto label4 = LabelTTF::create(TextUTF8::getCStringForKey("shezhi"), "Marker Felt", 32);
//	label4->setHorizontalAlignment(TextHAlignment::CENTER);
	label4->setColor(Color3B::BLACK);
	auto shezhiItem = MenuItemLabel::create(label4, CC_CALLBACK_1(HelloWorld::ReadArchive, this));
	shezhiItem->setPosition(Vec2(x, y + 40));


	// 退出
	auto label5 = LabelTTF::create(TextUTF8::getCStringForKey("tuichu"), "Marker Felt", 32);
	label5->setHorizontalAlignment(TextHAlignment::CENTER);
	label5->setColor(Color3B::BLACK);
	auto closeItem = MenuItemLabel::create(label5, CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
	closeItem->setPosition(Vec2(x, y + 0));


	auto menu = Menu::create(startItem, cundangItem, paimingItem, shezhiItem, closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);


//	Map<std::string, ccMenuCallback> map;
//	map.insert("button1", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

/*	std::map<std::string, ccMenuCallback> map;
	map.insert(std::pair<std::string, ccMenuCallback>("asas", CC_CALLBACK_1(HelloWorld::menuCloseCallback, this)));*/


	/*
		创建线程
	*/
	KeyMessages::CreateKeyMessageReceived();
	SpriteManager::CreateCollisionDetection();


    return true;
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}


void HelloWorld::StartTheGame(Ref* pSender) {
/*	auto dmGameControl = DMGameControl::newDMGameControl();
	dmGameControl->initDM();*/

	Director::getInstance()->pushScene(SelectLevelView::createScene());
}

void HelloWorld::ReadArchive(Ref* pSender) {

}