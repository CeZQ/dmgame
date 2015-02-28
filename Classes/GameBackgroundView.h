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
	
	// 初始化信息栏视图
	void initGameBackgroundView();

	// 玩家血量变化
	void playerHpBy(float percentageChange);
	// 玩家死亡方法
	void chongxin(Ref *ref);
	void chongxin2(Ref *ref);
	void fanhui(Ref *ref);
	// 玩家技能
	// 1.时停
	Sprite *stopTimeS;
	LabelTTF *stopTimeL;

	
	// 保存并退出   重新开始
//	void GameMessage();

	// BOSS 血量变化检测
	void bossHpBy(float percentageChange);
	void bossAttack(float f);

	static GameBackgroundView *getGameBackgroundView();		// 获取对象
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









/*	// 回收池需要的
DanMu *create();		// 创建
DanMu *remove();		// 释放
// 攻击类
bool init(int shangHai, int x, int y, const std::string imagePath);		// 初始化
void move();	// 移动  参数是动作序列之类的东西
// 碰撞检测
bool getYouXiao();		// 是否有效
float getShangHai();	// 伤害
private:
bool youXiao;
float shangHai;
int x, y, w, h;*/