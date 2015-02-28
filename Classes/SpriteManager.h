#ifndef __SPRITE_MANAGER__
#define __SPRITE_MANAGER__

#include "cocos2d.h"

#include "BaseSprite.h"

#include "BarrageSprite.h"

#include "CharacterSprite.h"
#include "PlayerSprite.h"
#include "BossSprite.h"

/*
	自定义精灵的管理类
	主要管理自定义精灵的创建 释放
	同时也负责碰撞检测
*/

class SpriteManager
{
public:


	// 碰撞检测
	static void CreateCollisionDetection();
	static bool startColl;
	static unsigned int __stdcall CollisionDetection(void *p);

	// 玩家控制人物
	PlayerSprite *playerSprite;
	// BOSS
	static BossSprite *BOSS;

	// NPC
//	static Vector<CharacterSprite *> NPC;
	

	
	static Vector<BarrageSprite *> Barrage;			// 弹幕容器
	static Vector<BarrageSprite *> _Barrage;		// 弹幕回收容器	

	static BarrageSprite *getBarrageSprite();		// 只保证返回一个可用弹幕对象，但是对于对象的值不做处理
	// 弹幕回收，  发现弹幕超出屏幕  标记无效  只做数据上的处理，不做UI上的处理 ， 界面更新交由主线程操作

	// 启动弹幕回收线程
	static void StartBarrageRecover();
	static unsigned int __stdcall BarrageRecover(void *p);



	// 清空弹幕池
	static void removeBarrage();
	// 暂停弹幕池弹幕
	static void pauseBarrage();
	// 恢复弹幕池弹幕
	static void resumeBarrage();

	// 暂停弹幕池弹幕
	static void pauseBarrage1();
	// 恢复弹幕池弹幕
	static void resumeBarrage1();


	/*
		打开 关闭 线程......
	*/
	

	static SpriteManager *getSpriteManager();
private:
	
	// 敌方弹幕
//	cocos2d::Vector<BaseSprite *> EnemyBarrage;


	static SpriteManager * spriteManager;
};







#endif



