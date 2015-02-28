#include "SpriteManager.h"

#include <process.h>

#include "DMGameControl.h"

USING_NS_CC;

SpriteManager * SpriteManager::spriteManager = NULL;


BossSprite *SpriteManager::BOSS = NULL;


bool SpriteManager::startColl = false;

Vector<BarrageSprite *> SpriteManager::Barrage;
Vector<BarrageSprite *> SpriteManager::_Barrage;
//Vector<CharacterSprite *> SpriteManager::NPC;


SpriteManager * SpriteManager::getSpriteManager() {
	if (spriteManager == NULL)
	{
		spriteManager = new SpriteManager;
	}
	return spriteManager;
}

/*
	从弹幕回收容器中获取一个弹幕对象， 如果回收容器为空，则新建一个弹幕对象返回  如果不为空，则把容器最后一个对象返回出去
*/
BarrageSprite *SpriteManager::getBarrageSprite() {
	BarrageSprite *barrSp;
	if (_Barrage.size() == 0)
	{
		log("new DM");
		barrSp = new BarrageSprite;
	}
	else {
		log("hs DM");
		barrSp = _Barrage.at(_Barrage.size()-1);
		_Barrage.popBack();
	}
	return barrSp;
}

/*
	弹幕重用    子线程 
*/
void SpriteManager::StartBarrageRecover() {
	_beginthreadex(NULL, 0, BarrageRecover, NULL, 0, NULL);
}
unsigned int __stdcall SpriteManager::BarrageRecover(void *p) {
	log("StartBarrageRecover");
	while (true)
	{
		for (int i = 0; i < SpriteManager::Barrage.size(); i++)
		{
			auto sp = SpriteManager::Barrage.at(i);
			if (sp->isEffective())
			{
				// 如果检测超出屏幕   
				// 首先标记无效
				// sp->Effective = false;
				// 然后从弹幕容器中移除
				// SpriteManager::Barrage.eraseObject(sp);
				// 之后在游戏图层的调度方法中每帧检测标记  如果无效则从图层中移除  并且加入回收容器
				// 考虑到内存的话，，，感觉可以限制一下弹幕重用容器的大小   比如超过200就释放掉一部分
			}
		}
	}
	return 0;
}


void SpriteManager::removeBarrage() {
	for (int i = 0; i < SpriteManager::Barrage.size(); i++)
	{
		auto sp = SpriteManager::Barrage.at(i);
		DMGameControl::getDMGameControl()->dmGameView->removeChild(sp);
	}
	SpriteManager::Barrage.clear();
	SpriteManager::_Barrage.clear();
}

/*
	暂停/继续 所有弹幕
*/

void SpriteManager::pauseBarrage() {
	for (int i = 0; i < SpriteManager::Barrage.size(); i++)
	{
		auto sp = SpriteManager::Barrage.at(i);
		sp->pauseSchedulerAndActions();
	}
}
void SpriteManager::resumeBarrage() {
	for (int i = 0; i < SpriteManager::Barrage.size(); i++)
	{
		auto sp = SpriteManager::Barrage.at(i);
		sp->resumeSchedulerAndActions();
	}
}

void SpriteManager::pauseBarrage1() {
	for (int i = 0; i < SpriteManager::Barrage.size(); i++)
	{
		auto sp = SpriteManager::Barrage.at(i);
		if (sp->Owner == 1)
		{
			sp->pauseSchedulerAndActions();
		}
	}
}
void SpriteManager::resumeBarrage1() {
	for (int i = 0; i < SpriteManager::Barrage.size(); i++)
	{
		auto sp = SpriteManager::Barrage.at(i);
		if (sp->Owner == 1)
		{
			sp->resumeSchedulerAndActions();
		}
	}
}

/*
	碰撞检测
*/
void SpriteManager::CreateCollisionDetection() {
	SpriteManager::startColl = false;
	_beginthreadex(NULL, 0, CollisionDetection, NULL, 0, NULL);
}

unsigned int __stdcall SpriteManager::CollisionDetection(void *p) {
	log("startCollisionDetection");
	while (true)
	{
		if (SpriteManager::startColl)
		{
			// 从弹幕容器中删除
/*			BarrageSprite *bss[1000] = { NULL };
			int n = 0;
			for (int i = 0; i < SpriteManager::Barrage.size(); i++)
			{
				auto sp = SpriteManager::Barrage.at(i);
				if (sp->VX == true)
				{
					bss[n++] = sp;
				}
			}

			for (int i = 0; i < n; i++)
			{
				SpriteManager::Barrage.eraseObject(bss[i]);
			//	bss[i]->VX = true;
			}*/

			// 从弹幕容器中删除
			BarrageSprite *bss[1000] = { NULL };
			int n = 0;
			for (int i = 0; i < SpriteManager::Barrage.size(); i++)
			{
				auto sp = SpriteManager::Barrage.at(i);
				if (sp->Effective == false)
				{
					bss[n++] = sp;
				}
			}
			for (int i = 0; i < n; i++)
			{
				SpriteManager::Barrage.eraseObject(bss[i]);
				bss[i]->VX = true;
			}


			/*
			弹幕坐标检测  如果无效  则标记无效  并且从容器中移除
			*/

			for (int i = 0; i < SpriteManager::Barrage.size(); i++)
			{
				auto sp = SpriteManager::Barrage.at(i);
				sp->isEffective();	// 检测是否超出范围
			}



			/*
			碰撞检测
			*/

			for (int i = 0; i < SpriteManager::Barrage.size(); i++)
			{
				auto sp = SpriteManager::Barrage.at(i);
				if (!sp->Effective)
				{
					continue;
				}

				Rect re;

				if (sp->Owner == 0)		// 己方弹幕  检测是否和敌方角色碰撞 
				{
					re = SpriteManager::BOSS->getBoundingBox();
					re.size = SpriteManager::BOSS->size;
					if (sp->isRect(re))
					{
						sp->Effective = false;
						SpriteManager::BOSS->HP_Change = SpriteManager::BOSS->HP -= sp->Hurt;
					}
				}
				else if (sp->Owner == 1)		// 敌方弹幕  检测是否和玩家碰撞
				{
					re = SpriteManager::getSpriteManager()->playerSprite->getBoundingBox();
					re.size = SpriteManager::getSpriteManager()->playerSprite->size;
					if (sp->isRect(re))
					{
						sp->Effective = false;
						SpriteManager::getSpriteManager()->playerSprite->HP_Change = SpriteManager::getSpriteManager()->playerSprite->HP -= sp->Hurt;
					}
				}
			}
		}
		else {
			Sleep(100);
			log("spriteManager");
		}
		
		Sleep(10);
	}
	return 0;
}