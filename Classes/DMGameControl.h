#ifndef __DMGAME_CONTROL__
#define __DMGAME_CONTROL__

#include "cocos2d.h"

#include "DMGameView.h"
#include "GameBackgroundView.h"

#include "SpriteManager.h"


// 人物


class DMGameControl :public cocos2d::Scene
{
public:

	~DMGameControl();

	static DMGameControl *newDMGameControl();
	static DMGameControl *getDMGameControl();

	CREATE_FUNC(DMGameControl);

	// 人物参数  关卡参数
	// 目前测试无參
	void initDM(int i);


	// 技能 时间暂停
	void pauseBoss();
	void resumeBoss(float f);

	SpriteManager *spriteManager;

	
	static GameBackgroundView *gameBackgroundView;
	static DMGameView *dmGameView;
private:
	int GK;

	

	static DMGameControl *dmGameControl;
};

#endif