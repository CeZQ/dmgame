#ifndef __CHARACTER_SPRITE__
#define __CHARACTER_SPRITE__


#include "BaseSprite.h"

/*
	角色类，继承至基础精灵类
	实现角色共有的属性方法
*/

class CharacterSprite : public BaseSprite
{
public:
	CharacterSprite();
	~CharacterSprite();


	void initCharacterSprite(Dictionary *dic);
	

	float HP;				// 生命值
	float HP_Change;		// 生命值变化

	float MAXHP;			// 最大生命值
	float Speed;			// 速度
	float AttackStrength;	// 攻击强度

private:

};





#endif