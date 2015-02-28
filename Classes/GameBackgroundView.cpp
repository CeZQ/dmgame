
#include "GameBackgroundView.h"

//#include "DMGameView.h"

#include "DMGameControl.h"

#include "SpriteManager.h"

#include "GameMessage2.h"
#include "TextUTF8.h"
#include "KeyMessages.h"

#include "SelectLevelView.h"

GameBackgroundView *GameBackgroundView::gameBackgroundView = NULL;

cocos2d::Scene* GameBackgroundView::createScene() {
	auto scene = Scene::create();
	auto layer = GameBackgroundView::create();
	scene->addChild(layer, 0);
	return scene;
}

bool GameBackgroundView::init() {
	if (!Layer::init())
	{
		return false;
	}

	/*
	
	*/
/*	playerHeadPortrait = Sprite::create();

	auto spr = Sprite::create("Load.png");
	spr->setScaleY(260.0f / spr->getBoundingBox().size.width);
	loadBar = ProgressTimer::create(spr);*/

	return true;
}


void GameBackgroundView::initGameBackgroundView() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();


	// 玩家信息
	// 人物头像
	playerHeadPortrait = Sprite::create(SpriteManager::getSpriteManager()->playerSprite->HeadImage[10]);
	playerHeadPortrait->setScale((visibleSize.width / 10.0f) / playerHeadPortrait->getBoundingBox().size.width);
	playerHeadPortrait->setPosition(Vec2((visibleSize.width / 10.0f) / 2 + 10.0f, visibleSize.height - (100.0f / 2.0f + 10.0f)));
	this->addChild(playerHeadPortrait, 1);

	// 血条
	auto spr = Sprite::create("Load.png");
	spr->setScaleY(260.0f / spr->getBoundingBox().size.width);
	loadBar = ProgressTimer::create(spr);
	loadBar->setPercentage(100.0f);
	loadBar->setPosition(10 + 100 + 10 + 130.0f, 670);
	loadBar->setType(ProgressTimerType::BAR);
	loadBar->setBarChangeRate(Vec2(1, 0));
	loadBar->setMidpoint(Vec2(0, 0));
	this->addChild(loadBar);
	auto prTo = ProgressFromTo::create(1.0f, 0, 100);
	loadBar->runAction(prTo);


	// 剩余血量
	auto str = String::createWithFormat("%.0f", SpriteManager::getSpriteManager()->playerSprite->HP);
	rwHP = LabelTTF::create(str->getCString(), "Marker Felt", 20);
	rwHP->setAnchorPoint(Vec2(0, 0));
	rwHP->setPosition(Vec2(120, 620));
	rwHP->setHorizontalAlignment(TextHAlignment::LEFT);
	rwHP->setColor(Color3B::BLACK);
	this->addChild(rwHP, 1);

	// 攻击
	// 移动速度

	// 每帧检测血量是否变化  如果变化 则处理动画效果
	schedule(schedule_selector(GameBackgroundView::playerHpBy));


	// 技能
	stopTimeS = Sprite::create("st.png");
	stopTimeS->setScale(40.0f / stopTimeS->getBoundingBox().size.width);
	stopTimeS->setAnchorPoint(Vec2(0, 0));
	stopTimeS->setPosition(Vec2(10, 540));
	this->addChild(stopTimeS, 1);


	// BOSS
	if (SpriteManager::BOSS == NULL)
	{
		return;
	}

	// 头像
	bossHeadPortrait = Sprite::create(SpriteManager::BOSS->HeadImage[10]);
	bossHeadPortrait->setScale(100.0f / bossHeadPortrait->getBoundingBox().size.width);
	bossHeadPortrait->setPosition(Vec2(visibleSize.width*0.94f, visibleSize.height - (100.0f / 2.0f + 10.0f)));
	this->addChild(bossHeadPortrait, 1);


	//血量
	bossLoadBar = ProgressTimer::create(spr);
	bossLoadBar->setPercentage(100.0f);
	bossLoadBar->setPosition(740, 670);
	bossLoadBar->setType(ProgressTimerType::BAR);
	bossLoadBar->setBarChangeRate(Vec2(1, 0));
	bossLoadBar->setMidpoint(Vec2(1, 0));
	this->addChild(bossLoadBar);
	auto prTo2 = ProgressFromTo::create(1.0f, 0, 100);
	bossLoadBar->runAction(prTo2);

	// 剩余血量
	auto str2 = String::createWithFormat("%.0f", SpriteManager::BOSS->HP);
	bossHP = LabelTTF::create(str2->getCString(), "Marker Felt", 20);
	bossHP->setAnchorPoint(Vec2(0, 0));
	bossHP->setPosition(Vec2(820, 620));
	bossHP->setHorizontalAlignment(TextHAlignment::RIGHT);
	bossHP->setColor(Color3B::BLACK);
	this->addChild(bossHP, 1);

	// 分数
	// 关卡
	// 保存

	schedule(schedule_selector(GameBackgroundView::bossHpBy));
	schedule(schedule_selector(GameBackgroundView::bossAttack));
}

void GameBackgroundView::playerHpBy(float percentageChange) {	// 进度变化值
	// 
	if (SpriteManager::getSpriteManager()->playerSprite->Attack_O_FPS_ == 0)
	{
		if (SpriteManager::getSpriteManager()->playerSprite->OX == false)
		{
			stopTimeS->setTexture("st.png");
			SpriteManager::getSpriteManager()->playerSprite->OX = true;
		}
	}
	else {
		if (SpriteManager::getSpriteManager()->playerSprite->OX == true) {
			stopTimeS->setTexture("st2.png");
			SpriteManager::getSpriteManager()->playerSprite->OX = false;
		}
	}


	// HP
	float hp_Change = SpriteManager::getSpriteManager()->playerSprite->HP_Change;
	if (hp_Change != 0.0f)
	{
		float hp = SpriteManager::getSpriteManager()->playerSprite->HP;
		float maxHp = SpriteManager::getSpriteManager()->playerSprite->MAXHP;
		if (hp_Change >= maxHp)
		{
			// 超过生命值上限
			hp_Change = maxHp;
		}
		else if (hp_Change <= 0)
		{
			// 死亡
			hp_Change = 0.0f;
			// 改变信息栏数据
			// 调用角色死亡方法
			auto prTo = ProgressFromTo::create(0.0f, hp / maxHp * 100, 0);
			loadBar->runAction(prTo);
			// 释放所有弹幕池
			SpriteManager::removeBarrage();

			map<string, ccMenuCallback> map;
			//auto dic = Dictionary::createWithContentsOfFile("qiandai.xml");
			auto dic2 = Dictionary::createWithContentsOfFile("Text_CN2.xml");
			map.insert(pair<string, ccMenuCallback>(
				dic2->valueForKey("chongxin")->getCString(), CC_CALLBACK_1(GameBackgroundView::chongxin, this)));
			map.insert(pair<string, ccMenuCallback>(
				dic2->valueForKey("fanhui")->getCString(), CC_CALLBACK_1(GameBackgroundView::fanhui, this)));
			GameMessage2::newGameMessage(this, ((String *)dic2->objectForKey("title"))->getCString(),
				((String *)dic2->objectForKey("message"))->getCString(),
				map,
				"duihuakuang.png"
				);
		}
		float toPercentage = hp_Change / maxHp * 100;
		// 血量变化时头像的变化
		int nIn = (int)toPercentage / 10;
		nIn = ((nIn == 0) && toPercentage != 0) ? 1 : nIn;
		playerHeadPortrait->setTexture(SpriteManager::getSpriteManager()->playerSprite->HeadImage[nIn]);
		// 执行动作
		auto prTo = ProgressFromTo::create(0.0f, hp / maxHp * 100, toPercentage);
		loadBar->runAction(prTo);
		SpriteManager::getSpriteManager()->playerSprite->HP = hp_Change;
		SpriteManager::getSpriteManager()->playerSprite->HP_Change = 0.0f;
		// 更新标签值
		auto st = String::createWithFormat("%.0f", hp_Change);
		rwHP->setString(st->getCString());
	}
}

void GameBackgroundView::chongxin(Ref *ref) {
	KeyMessages::PR();
	Director::getInstance()->popScene();
	SelectLevelView::selectX = 7001;
}
void GameBackgroundView::chongxin2(Ref *ref) {
	KeyMessages::PR();
	Director::getInstance()->popScene();
	SelectLevelView::selectX = 7002;
}
void GameBackgroundView::fanhui(Ref *ref) {
	KeyMessages::PR();
	Director::getInstance()->popScene();
}

void GameBackgroundView::bossAttack(float f) {
	SpriteManager::BOSS->gongji(this);
}

void GameBackgroundView::bossHpBy(float percentageChange) {
	


	float hp_Change = SpriteManager::BOSS->HP_Change;
	if (hp_Change != 0.0f)
	{
		float hp = SpriteManager::BOSS->HP;
		float maxHp = SpriteManager::BOSS->MAXHP;
		if (hp_Change >= maxHp)
		{
			// 超过生命值上限
			hp_Change = maxHp;
		}
		else if (hp_Change <= 0)
		{
			// 死亡
			hp_Change = 0.0f;
			// 改变信息栏数据
			// 调用角色死亡方法
			auto prTo = ProgressFromTo::create(0.0f, hp / maxHp * 100, 0);
			bossLoadBar->runAction(prTo);
			// 释放所有弹幕池
			SpriteManager::removeBarrage();


			map<string, ccMenuCallback> map;
			auto dic2 = Dictionary::createWithContentsOfFile("Text_CN2.xml");
			map.insert(pair<string, ccMenuCallback>(
				dic2->valueForKey("chongxin")->getCString(), CC_CALLBACK_1(GameBackgroundView::chongxin2, this)));
			map.insert(pair<string, ccMenuCallback>(
				dic2->valueForKey("fanhui")->getCString(), CC_CALLBACK_1(GameBackgroundView::fanhui, this)));
			GameMessage2::newGameMessage(this, "yes",
				"aaaaaaa",
				map,
				"duihuakuang.png"
				);

		}
		float toPercentage = hp_Change / maxHp * 100;
		// 血量变化时头像的变化
		int nIn = (int)toPercentage / 10;
		nIn = ((nIn == 0) && toPercentage != 0) ? 1 : nIn;
		bossHeadPortrait->setTexture(SpriteManager::BOSS->HeadImage[nIn]);
		// 执行动作
		auto prTo = ProgressFromTo::create(0.0f, hp / maxHp * 100, toPercentage);
		bossLoadBar->runAction(prTo);

		SpriteManager::BOSS->HP = hp_Change;
		SpriteManager::BOSS->HP_Change = 0.0f;
		// 更新标签值
		auto st = String::createWithFormat("%.0f", hp_Change);
		bossHP->setString(st->getCString());
	}
}