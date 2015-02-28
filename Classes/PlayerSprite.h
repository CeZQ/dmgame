#ifndef __PLAYER_SPRITE__
#define __PLAYER_SPRITE__

#include "CharacterSprite.h"



/*
	玩家类
	继承自角色类
*/

class PlayerSprite : public CharacterSprite
{
public:
	PlayerSprite();
	~PlayerSprite();
	
	void initPlayerSprite(const std::string xmlPath);
	
	// 头像
	std::string HeadImage[11];


	// 攻击？
	bool Attack_I;
	int Attack_I_FPS, Attack_I_FPS_;

	void Attack_I_Fun(Layer *layer);			// 普通攻击函数


	//
	bool Attack_J, Attack_K, Attack_L;

	// 技能
	bool OX;
	// 时间暂停
	bool Attack_O; // 释放技能
	int Attack_O_FPS, Attack_O_FPS_;	// 冷却时间
	int Attack_O_CX, Attack_O_CX_;	// 持续帧
	void Attack_O_Fun();





private:

	// 攻击方式

	// 普通攻击

	// 
};


#endif