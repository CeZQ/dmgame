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

	// ��ͨ����  Ĭ�Ϲر�
	Attack_I = false;
	Attack_I_FPS = 20;	// ʮ֡һ��
	Attack_I_FPS_ = 0;

	// ����O  ʱ����ͣ
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

	// �ھ���
	size.width = getBoundingBox().size.width * 0.6f;
	size.height = getBoundingBox().size.height * 0.6f;
}



/*
	��ͨ����
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
		--Attack_O_FPS_;  // ��ȴʱ�����
	}
	else {
	//	OX = true;
	}

	if (Attack_O_CX_ != 0)	// ����ʱ��
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
			// ʱ����ͣ
			DMGameControl::getDMGameControl()->pauseBoss();
			//
			Attack_O_FPS_ = Attack_O_FPS;	// ������ȴ
			Attack_O = false;				// �ɹ��ͷ�
			Attack_O_CX_ = 1;

		//	OX = false;
		}
	}
	
	if (Attack_O_FPS_ % 60 == 0)	// ÿ�����ü����ͷ�
	{
		Attack_O = false;
	}
}

