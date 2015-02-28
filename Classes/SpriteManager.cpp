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
	�ӵ�Ļ���������л�ȡһ����Ļ���� �����������Ϊ�գ����½�һ����Ļ���󷵻�  �����Ϊ�գ�����������һ�����󷵻س�ȥ
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
	��Ļ����    ���߳� 
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
				// �����ⳬ����Ļ   
				// ���ȱ����Ч
				// sp->Effective = false;
				// Ȼ��ӵ�Ļ�������Ƴ�
				// SpriteManager::Barrage.eraseObject(sp);
				// ֮������Ϸͼ��ĵ��ȷ�����ÿ֡�����  �����Ч���ͼ�����Ƴ�  ���Ҽ����������
				// ���ǵ��ڴ�Ļ��������о���������һ�µ�Ļ���������Ĵ�С   ���糬��200���ͷŵ�һ����
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
	��ͣ/���� ���е�Ļ
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
	��ײ���
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
			// �ӵ�Ļ������ɾ��
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

			// �ӵ�Ļ������ɾ��
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
			��Ļ������  �����Ч  ������Ч  ���Ҵ��������Ƴ�
			*/

			for (int i = 0; i < SpriteManager::Barrage.size(); i++)
			{
				auto sp = SpriteManager::Barrage.at(i);
				sp->isEffective();	// ����Ƿ񳬳���Χ
			}



			/*
			��ײ���
			*/

			for (int i = 0; i < SpriteManager::Barrage.size(); i++)
			{
				auto sp = SpriteManager::Barrage.at(i);
				if (!sp->Effective)
				{
					continue;
				}

				Rect re;

				if (sp->Owner == 0)		// ������Ļ  ����Ƿ�͵з���ɫ��ײ 
				{
					re = SpriteManager::BOSS->getBoundingBox();
					re.size = SpriteManager::BOSS->size;
					if (sp->isRect(re))
					{
						sp->Effective = false;
						SpriteManager::BOSS->HP_Change = SpriteManager::BOSS->HP -= sp->Hurt;
					}
				}
				else if (sp->Owner == 1)		// �з���Ļ  ����Ƿ�������ײ
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