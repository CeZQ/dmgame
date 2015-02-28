#ifndef __DMGAME_CONTROL__
#define __DMGAME_CONTROL__

#include "cocos2d.h"

#include "DMGameView.h"
#include "GameBackgroundView.h"

#include "SpriteManager.h"


// ����


class DMGameControl :public cocos2d::Scene
{
public:

	~DMGameControl();

	static DMGameControl *newDMGameControl();
	static DMGameControl *getDMGameControl();

	CREATE_FUNC(DMGameControl);

	// �������  �ؿ�����
	// Ŀǰ�����ޅ�
	void initDM(int i);


	// ���� ʱ����ͣ
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