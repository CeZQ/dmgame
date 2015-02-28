#include "DMGameControl.h"



#include "TestView.h"
#include "KeyMessages.h"

#include "TextUTF8.h"

#include "Attack.h"

#include "SelectLevelView.h"

USING_NS_CC;

DMGameControl * DMGameControl::dmGameControl = NULL;

GameBackgroundView * DMGameControl::gameBackgroundView = NULL;
DMGameView * DMGameControl::dmGameView = NULL;

DMGameControl::~DMGameControl() {
	log("~~~~~~~~~~~~~~~~~~~~~~~~");

	// 清空弹幕池
	SpriteManager::getSpriteManager()->playerSprite == NULL;
	SpriteManager::BOSS = NULL;
	SpriteManager::removeBarrage();

	// 关闭按键消息线程
	KeyMessages::start = false;
	SpriteManager::startColl = false;

	// 
}

DMGameControl *DMGameControl::newDMGameControl() {

	dmGameControl = NULL;


	return DMGameControl::getDMGameControl();
}

DMGameControl * DMGameControl::getDMGameControl() {
	if (dmGameControl == NULL)
	{
		DMGameControl::dmGameControl = DMGameControl::create();


		// 背景图
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();

		auto sprite = Sprite::create("BG.png");
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		dmGameControl->addChild(sprite, 0);


		// 游戏图层  信息栏图层  
		dmGameView = DMGameView::create();
		gameBackgroundView = GameBackgroundView::create();

		dmGameControl->addChild(dmGameView, 0);
		dmGameControl->addChild(gameBackgroundView, 1);

		// 
	//	dmGameControl->addChild(TestView::create(), 1);
	}
	return DMGameControl::dmGameControl;
}

void DMGameControl::initDM(int i) {
	// 初始化界面
	SelectLevelView::selectX = 0.0f;
	

	auto player = new PlayerSprite;
	player->initPlayerSprite("qiandai.xml");
	this->addChild(player, 1);


	
	
	
	switch (i)
	{
	case 7001:
		dmGameView->Level1();
		break;
	case 7002:
		dmGameView->Level2();
		break;
	default:
		break;
	}

	GK = i;

	gameBackgroundView->initGameBackgroundView();
	dmGameView->initDMGameView();
	dmGameView->initBarrageDealWith();

	KeyMessages::start = true;
	SpriteManager::startColl = true;
	// 启动按键消息接收
/*	auto key = KeyMessages::getKeyMessages();
	key->StartKeyMessageReceived();*/
	// 开启碰撞检测
	//SpriteManager::getSpriteManager()->startCollisionDetection();
}

// 技能 时间暂停
void DMGameControl::pauseBoss() {
	if (GK == 7002)
	{
		gameBackgroundView->unschedule(schedule_selector(GameBackgroundView::bossAttack));
	}
	SpriteManager::pauseBarrage1();
}
void DMGameControl::resumeBoss(float f) {
	if (GK == 7002)
	{
		gameBackgroundView->schedule(schedule_selector(GameBackgroundView::bossAttack));
	}
	SpriteManager::resumeBarrage1();
}