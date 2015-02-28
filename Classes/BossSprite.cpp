#include "BossSprite.h"
#include "SpriteManager.h"

#include "Attack.h"

BossSprite::BossSprite()
{
	SpriteManager::BOSS = this;
}

BossSprite::~BossSprite()
{
}


void BossSprite::initBossSprite(const char * xmlPath) {
	auto dic = Dictionary::createWithContentsOfFile(xmlPath);

	initCharacterSprite(dic);

	Size visibleSize = Director::getInstance()->getVisibleSize();


	setPosition(Vec2(visibleSize.width/2, visibleSize.height*0.9));
	setScale(1);
	//	
	char buf[100] = { 0 };
	for (int i = 0; i < 11; i++)
	{
		memset(buf, 0, 100);
		sprintf_s(buf, "HP%d", i * 10);
		HeadImage[i].assign(dic->valueForKey(buf)->getCString());
	}

	// ÄÚ¾ØÐÎ
	size.width = getBoundingBox().size.width * 0.6f;
	size.height = getBoundingBox().size.height * 0.6f;

	z = 0;
}


void BossSprite::gongji(Layer *layer) {
	++z;
	if (z % 60 == 0)
	{
		int i = rand() % 20;
		i = i < 10 ? 0 : i < 14 ? 1 : i < 19 ? 2 : 3;
		switch (i)
		{
		case 0:
			Attack::yuan(layer, 1, getPosition(), z % 360, 20 + rand() % 3 * 6, 360, rand() % 6, 10, AttackStrength);
			break;
		case 1:
			Attack::yuan(layer, 1, getPosition(), 270, 6, 180, 12, 20, 3.0f);
			//Attack::Beeline(layer, 1, getPosition(), 270.0f, 12, 20, 3.0f);
			break;
		case 2:
			break;
		case 3:
			Attack::Practice(layer, 8, SpriteManager::getSpriteManager()->playerSprite->getBoundingBox(), 16);
			break;
		default:
			break;
		}
		
	}
}