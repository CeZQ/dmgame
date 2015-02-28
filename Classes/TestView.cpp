#include "TestView.h"

#include "DMGameControl.h"
#include "SpriteManager.h"
#include "KeyMessages.h"


#include "Attack.h"


USING_NS_CC;


bool TestView::init() {
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	
	// 血量减少
	auto label = LabelTTF::create("HP -40", "Marker Felt", 32);
	label->setHorizontalAlignment(TextHAlignment::CENTER);
	label->setColor(Color3B::BLACK);
	auto menuItem = MenuItemLabel::create(label, CC_CALLBACK_1(TestView::bu1, this));
	menuItem->setPosition(Vec2(visibleSize.width / 4, visibleSize.height - 200));

	// 血量增加
	auto label2 = LabelTTF::create("HP +40", "Marker Felt", 32);
	label2->setHorizontalAlignment(TextHAlignment::CENTER);
	label2->setColor(Color3B::BLACK);
	auto hpAdd = MenuItemLabel::create(label2, CC_CALLBACK_1(TestView::hpadd, this));
	hpAdd->setPosition(Vec2(visibleSize.width / 4, visibleSize.height - 230));



	// 弹幕测试
	auto label3 = LabelTTF::create("DM_Test", "Marker Felt", 32);
	label3->setHorizontalAlignment(TextHAlignment::CENTER);
	label3->setColor(Color3B::BLACK);
	auto dmTest = MenuItemLabel::create(label3, CC_CALLBACK_1(TestView::DMTest, this));
	dmTest->setPosition(Vec2(visibleSize.width / 4, visibleSize.height - 260));



	auto starMenu = Menu::create(menuItem, hpAdd, dmTest, NULL);
	starMenu->setPosition(Point::ZERO);
	this->addChild(starMenu, 1);
	

	gj = gongjifangshi();
	gj.layer = this;
	

	// 加个精灵看看 
/*	sp = Sprite::create("HH.png");
	sp->setPosition(Vec2(400,400));
	this->addChild(sp, 1);*/

	///

/*	auto key = KeyMessages::getKeyMessages();
	key->BindingMessageHandler(this, callfuncO_selector(TestView::keymsg), VK_UP, "move_up");
	key->StartKeyMessageReceived();*/

//	schedule(schedule_selector(TestView::keymsg));

	return true;
}

void TestView::keymsg(float f) {
	log("TestView::keymsg");
}



void TestView::bu1(Ref* pSender) {
//	DMGameControl::getDMGameControl()->pauseSchedulerAndActions();
//	SpriteManager::pauseAll();

	log("HP -40");
	auto f = Float::create(-40.0f);
	NotificationCenter::getInstance()->postNotification("rwhp", f);
}
void TestView::hpadd(Ref* pSender) {
	DMGameControl::getDMGameControl()->resumeSchedulerAndActions();


	log("HP +40");
	auto f = Float::create(40.0f);
	NotificationCenter::getInstance()->postNotification("rwhp", f);
}

void TestView::DMTest(Ref* ref) {
	Attack::Practice(this, 10, Rect(400,250,200,200), 10);
//	gj.yuan(0, Vec2(500, 350), 5, 0, 10);
//	auto re = Rect(sp->getBoundingBox().getMinX(), sp->getBoundingBox().getMinY(), sp->getBoundingBox().size.width, sp->getBoundingBox().size.height);
//	gj.quanping1(0, 40, re, 0, 10);
}