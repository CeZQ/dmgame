#include "DMGameView.h"

#include "SpriteManager.h"
#include "KeyMessages.h"
#include "Attack.h"

#include "GameMessage2.h"

#include "TextUTF8.h"

USING_NS_CC;

DMGameView::~DMGameView() {
	log("~~~~~~~~~~~~");

	
}


cocos2d::Scene* DMGameView::createScene() {
	auto scene = Scene::create();
	auto layer = DMGameView::create();
	scene->addChild(layer);
	return scene;
}

bool DMGameView::init() {
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	


	return true;
}


void DMGameView::initDMGameView() {
	
	

	// 移动
	schedule(schedule_selector(DMGameView::playerMove));
	// 攻击
//	schedule(schedule_selector(DMGameView::Attack_N));

}








/*
	人物移动和普通攻击
*/
void DMGameView::playerMove(float f){
	// 移动
	Vec2 v2 = Vec2::ZERO;
	v2 = KeyMessages::getKeyMessages()->ve;
	Vec2 ve = SpriteManager::getSpriteManager()->playerSprite->getPosition();
	ve += v2;
	if (ve.x >= 1000 || ve.x <= 0 || ve.y >= 700 || ve.y <= 0)
	{
	}
	else {
		SpriteManager::getSpriteManager()->playerSprite->setPosition(ve);
	}

	// 普通攻击
	if (SpriteManager::getSpriteManager()->playerSprite->Attack_I)
	{
		SpriteManager::getSpriteManager()->playerSprite->Attack_I_Fun(this);
	}

	// 技能 
	SpriteManager::getSpriteManager()->playerSprite->Attack_O_Fun();

}
void DMGameView::Attack_N(float f) {
	
}


/*
	关于弹幕的碰撞处理  和  回收处理
*/
void DMGameView::initBarrageDealWith() {
//	schedule(schedule_selector(DMGameView::CollisionDealWith), 1.0f);
	// 开始弹幕无效检测线程
//	SpriteManager::StartBarrageRecover();

	log("Start EffectiveDealWith");
	schedule(schedule_selector(DMGameView::EffectiveDealWith));
}
void DMGameView::CollisionDealWith(float f) {// 碰撞处理

	log("%d %d", SpriteManager::Barrage.size(), SpriteManager::_Barrage.size());

}
/*
	弹幕无效处理函数   
*/
void DMGameView::EffectiveDealWith(float f) {
	for (int i = 0; i < SpriteManager::Barrage.size(); i++)
	{
		auto sp = SpriteManager::Barrage.at(i);
		if (!sp->Effective)
		{
			sp->Recover(this);
		}
	}
}


	


/*
	第一关
*/

void DMGameView::Level1() {
	Size visibleSize = Director::getInstance()->getVisibleSize();

	

//	fps = 60 * 60;
	fps = 0;

	auto str = String::createWithFormat("%d", fps);
	auto la = LabelTTF::create(str->getCString(), "Marker Felt", 20);

	la->setTag(301);	// Tag
	
	la->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.8));
	la->setHorizontalAlignment(TextHAlignment::CENTER);
	la->setColor(Color3B::BLACK);
	this->addChild(la, 1);

	// 初始  弹幕攻击练习
	Attack::Practice(this, 14, SpriteManager::getSpriteManager()->playerSprite->getBoundingBox(), 16);
	schedule(schedule_selector(DMGameView::__Practice));


	
}

void DMGameView::level1_1_yes(Ref *ref) {
	GameMessage2::remove(this);
}
void DMGameView::level1_1_no(Ref *ref) {
	KeyMessages::PR();

	Director::getInstance()->popScene();
	//Director::getInstance()->popToRootScene();
}

void DMGameView::__Practice(float f) {
//	if (fps == 60*60)
	if (fps == 0)
	{
		map<string, ccMenuCallback> map;
		auto dic = Dictionary::createWithContentsOfFile("Level1.xml");
		map.insert(pair<string, ccMenuCallback>(TextUTF8::getCStringForKey("queding"), CC_CALLBACK_1(DMGameView::level1_1_yes, this)));
		map.insert(pair<string, ccMenuCallback>(TextUTF8::getCStringForKey("quxiao"), CC_CALLBACK_1(DMGameView::level1_1_no, this)));
		GameMessage2::newGameMessage(this, ((String *)dic->objectForKey("title1"))->getCString(),
			((String *)dic->objectForKey("message1"))->getCString(),
			map,
			((String *)dic->objectForKey("image1"))->getCString()
			);
	}

	if (fps%60==0)
	{
		auto la = (LabelTTF *)getChildByTag(301);
		auto str = String::createWithFormat("%d", fps/60);
		la->setString(str->getCString());
	}
	

//	if (fps == 0)
	if (0)
	{
		SpriteManager::removeBarrage();
		log("rm");
		unschedule(schedule_selector(DMGameView::__Practice));
		log("un");
		// 通关
		removeChildByTag(301);

		auto dic = Dictionary::createWithContentsOfFile("Level1.xml");
		map<string, ccMenuCallback> map;
		map.insert(pair<string, ccMenuCallback>(TextUTF8::getCStringForKey("queding"), CC_CALLBACK_1(DMGameView::level1_1_yes, this)));
		map.insert(pair<string, ccMenuCallback>(TextUTF8::getCStringForKey("quxiao"), CC_CALLBACK_1(DMGameView::level1_1_no, this)));
		GameMessage2::newGameMessage(this, ((String *)dic->objectForKey("title2"))->getCString(),
			((String *)dic->objectForKey("message2"))->getCString(),
			map,
			((String *)dic->objectForKey("image2"))->getCString()
			);
		return;
	}
/*	for (int i = 0; i < SpriteManager::getSpriteManager()->Barrage.size(); i++)
	{
		auto sp = SpriteManager::getSpriteManager()->Barrage.at(i);
		sp->isEffective();
		if (!sp->Effective)
		{
			Attack::_Practice(sp, this, SpriteManager::getSpriteManager()->playerSprite->getBoundingBox(), 10);
		}
	}*/
	if (SpriteManager::Barrage.size() < 56)
	{
		auto sp = SpriteManager::getBarrageSprite();
		Attack::_Practice(sp, this, SpriteManager::getSpriteManager()->playerSprite->getBoundingBox(), 16);
	}

	log("%d", SpriteManager::Barrage.size());
//	--fps;
	++fps;
}


/*
	第二关
*/
void DMGameView::Level2() {
	auto boss = new BossSprite;
	boss->initBossSprite("BOSS1.xml");
	this->addChild(boss, 1);
}
