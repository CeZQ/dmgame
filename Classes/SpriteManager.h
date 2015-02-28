#ifndef __SPRITE_MANAGER__
#define __SPRITE_MANAGER__

#include "cocos2d.h"

#include "BaseSprite.h"

#include "BarrageSprite.h"

#include "CharacterSprite.h"
#include "PlayerSprite.h"
#include "BossSprite.h"

/*
	�Զ��徫��Ĺ�����
	��Ҫ�����Զ��徫��Ĵ��� �ͷ�
	ͬʱҲ������ײ���
*/

class SpriteManager
{
public:


	// ��ײ���
	static void CreateCollisionDetection();
	static bool startColl;
	static unsigned int __stdcall CollisionDetection(void *p);

	// ��ҿ�������
	PlayerSprite *playerSprite;
	// BOSS
	static BossSprite *BOSS;

	// NPC
//	static Vector<CharacterSprite *> NPC;
	

	
	static Vector<BarrageSprite *> Barrage;			// ��Ļ����
	static Vector<BarrageSprite *> _Barrage;		// ��Ļ��������	

	static BarrageSprite *getBarrageSprite();		// ֻ��֤����һ�����õ�Ļ���󣬵��Ƕ��ڶ����ֵ��������
	// ��Ļ���գ�  ���ֵ�Ļ������Ļ  �����Ч  ֻ�������ϵĴ�������UI�ϵĴ��� �� ������½������̲߳���

	// ������Ļ�����߳�
	static void StartBarrageRecover();
	static unsigned int __stdcall BarrageRecover(void *p);



	// ��յ�Ļ��
	static void removeBarrage();
	// ��ͣ��Ļ�ص�Ļ
	static void pauseBarrage();
	// �ָ���Ļ�ص�Ļ
	static void resumeBarrage();

	// ��ͣ��Ļ�ص�Ļ
	static void pauseBarrage1();
	// �ָ���Ļ�ص�Ļ
	static void resumeBarrage1();


	/*
		�� �ر� �߳�......
	*/
	

	static SpriteManager *getSpriteManager();
private:
	
	// �з���Ļ
//	cocos2d::Vector<BaseSprite *> EnemyBarrage;


	static SpriteManager * spriteManager;
};







#endif



