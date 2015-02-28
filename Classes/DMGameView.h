#ifndef __DMGAME_VIEW__
#define __DMGAME_VIEW__

#include "cocos2d.h"


USING_NS_CC;

class DMGameView :public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(DMGameView);

	void initDMGameView();

	~DMGameView();


	int fps;
	// 移动
	void playerMove(float f);
	// 攻击
	void Attack_N(float f);


	
	/*
		每帧需要处理的
		弹幕碰撞   弹幕回收
	*/
	void initBarrageDealWith();			// 开始弹幕处理
	void CollisionDealWith(float f);	// 弹幕碰撞处理
	void EffectiveDealWith(float f);	// 弹幕无效处理


	/*
		第一关的处理函数
	*/
	


	/*
		关卡
	*/
	

//	Dictionary *dic;
	// 关卡
	void Level1();
	void __Practice(float f);	// 弹幕躲避练习...
	void level1_1_yes(Ref *ref);
	void level1_1_no(Ref *ref);

	void Level2();
	void Level3();
	void Level4();

private:

};




#endif