#ifndef __GAME_BACKGROUND_VIEW__
#define __GAME_BACKGROUND_VIEW__

#include "cocos2d.h"

USING_NS_CC;

using namespace std;

class GameBackgroundView : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(GameBackgroundView);
	
	// ��ʼ����Ϣ����ͼ
	void initGameBackgroundView();

	// ���Ѫ���仯
	void playerHpBy(float percentageChange);
	// �����������
	void chongxin(Ref *ref);
	void chongxin2(Ref *ref);
	void fanhui(Ref *ref);
	// ��Ҽ���
	// 1.ʱͣ
	Sprite *stopTimeS;
	LabelTTF *stopTimeL;

	
	// ���沢�˳�   ���¿�ʼ
//	void GameMessage();

	// BOSS Ѫ���仯���
	void bossHpBy(float percentageChange);
	void bossAttack(float f);

	static GameBackgroundView *getGameBackgroundView();		// ��ȡ����
private:

	Sprite *playerHeadPortrait;
	Sprite *bossHeadPortrait;

	cocos2d::LabelTTF *rwHP;
	cocos2d::ProgressTimer *loadBar;


	cocos2d::LabelTTF *bossHP;
	cocos2d::ProgressTimer *bossLoadBar;

	static GameBackgroundView *gameBackgroundView;
};




#endif









/*	// ���ճ���Ҫ��
DanMu *create();		// ����
DanMu *remove();		// �ͷ�
// ������
bool init(int shangHai, int x, int y, const std::string imagePath);		// ��ʼ��
void move();	// �ƶ�  �����Ƕ�������֮��Ķ���
// ��ײ���
bool getYouXiao();		// �Ƿ���Ч
float getShangHai();	// �˺�
private:
bool youXiao;
float shangHai;
int x, y, w, h;*/