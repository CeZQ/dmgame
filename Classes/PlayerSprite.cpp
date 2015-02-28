#include "PlayerSprite.h"

#include "SpriteManager.h"

#include "Attack.h"

#include "DMGameControl.h"

USING_NS_CC;

PlayerSprite::PlayerSprite()
{
	//
	SpriteManager::getSpriteManager()->playerSprite = this;
	log("PlayerSprite");
}

PlayerSprite::~PlayerSprite()
{
	log("~PlayerSprite");
}


void  PlayerSprite::initPlayerSprite(const std::string xmlPath) {
	auto dic = Dictionary::createWithContentsOfFile("qiandai.xml");

	// 普通攻击  默认关闭
	Attack_I = false;
	Attack_I_FPS = 20;	// 十帧一发
	Attack_I_FPS_ = 0;

	// 技能O  时间暂停
	Attack_O = false;
	Attack_O_FPS = 60 * 20;
	Attack_O_FPS_ = 0;
	Attack_O_CX = 60 * 4;
	Attack_O_CX_ = 0;
	OX = true;


	initCharacterSprite(dic);
	
	//	
	char buf[100] = { 0 };
	for (int i = 0; i < 11; i++)
	{
		memset(buf, 0, 100);
		sprintf_s(buf, "HP%d", i * 10);
		HeadImage[i].assign(dic->valueForKey(buf)->getCString());
	}

	// 内矩形
	size.width = getBoundingBox().size.width * 0.6f;
	size.height = getBoundingBox().size.height * 0.6f;
}



/*
	普通攻击
*/
void PlayerSprite::Attack_I_Fun(Layer *layer) {
	++Attack_I_FPS_;
	if (Attack_I_FPS == Attack_I_FPS_)
	{
		Attack::Beeline(layer, 0, getPosition(), 90.0f, 9, 4, AttackStrength);
		Attack_I_FPS_ = 0;
	}
}

void PlayerSprite::Attack_O_Fun() {
	if (Attack_O_FPS_ != 0)
	{
		--Attack_O_FPS_;  // 冷却时间减少
	}
	else {
	//	OX = true;
	}

	if (Attack_O_CX_ != 0)	// 持续时间
	{
		++Attack_O_CX_;
		if (Attack_O_CX_ == Attack_O_CX)
		{
			DMGameControl::getDMGameControl()->scheduleOnce(schedule_selector(DMGameControl::resumeBoss), 0.0f);
			Attack_O_CX_ = 0;
		}
	}

	if (Attack_O)
	{
		if (Attack_O_FPS_ == 0)
		{
			// 时间暂停
			DMGameControl::getDMGameControl()->pauseBoss();
			//
			Attack_O_FPS_ = Attack_O_FPS;	// 进入冷却
			Attack_O = false;				// 成功释放
			Attack_O_CX_ = 1;

		//	OX = false;
		}
	}
	
	if (Attack_O_FPS_ % 60 == 0)	// 每秒重置技能释放
	{
		Attack_O = false;
	}
}

