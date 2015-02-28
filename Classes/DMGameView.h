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
	// �ƶ�
	void playerMove(float f);
	// ����
	void Attack_N(float f);


	
	/*
		ÿ֡��Ҫ�����
		��Ļ��ײ   ��Ļ����
	*/
	void initBarrageDealWith();			// ��ʼ��Ļ����
	void CollisionDealWith(float f);	// ��Ļ��ײ����
	void EffectiveDealWith(float f);	// ��Ļ��Ч����


	/*
		��һ�صĴ�����
	*/
	


	/*
		�ؿ�
	*/
	

//	Dictionary *dic;
	// �ؿ�
	void Level1();
	void __Practice(float f);	// ��Ļ�����ϰ...
	void level1_1_yes(Ref *ref);
	void level1_1_no(Ref *ref);

	void Level2();
	void Level3();
	void Level4();

private:

};




#endif