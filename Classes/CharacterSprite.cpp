#include "CharacterSprite.h"

USING_NS_CC;

CharacterSprite::CharacterSprite()
{
	log("CharacterSprite");
}

CharacterSprite::~CharacterSprite()
{
	log("~CharacterSprite");
}


void CharacterSprite::initCharacterSprite(Dictionary *dic) {
	const std::string image(dic->valueForKey("image")->getCString());

	HP_Change = false;

	// Í¼Ïñ
	setTexture(image);
	setScale(60.0f / getBoundingBox().size.width);

	// ³õÊ¼Î»ÖÃ
	Size visibleSize = Director::getInstance()->getVisibleSize();
	setPosition(Vec2(visibleSize.width / 2.0f, visibleSize.height / 3.0f));


	HP = dic->valueForKey("MAXHP")->floatValue();
	MAXHP = HP;
	Speed = dic->valueForKey("Speed")->floatValue();
	AttackStrength = dic->valueForKey("AttackStrength")->floatValue();
	// 
}
