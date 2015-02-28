#include "Attack.h"

#include "SpriteManager.h"

#include "DMGameControl.h"

Attack::Attack()
{
}

Attack::~Attack()
{
}

#define H 1700

void Attack::Practice(Layer *layer, int number, Rect re, float time) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 v2;
	for (int i = 0; i < 4; i++)
	{
		for (int n = 0; n < number; n++)
		{
			//���ó�����
			switch (i)
			{
			case 0: v2.y = 0;  v2.x = rand() % (int)(visibleSize.width);   break;
			case 1: v2.y = visibleSize.height; v2.x = rand() % (int)(visibleSize.width - 5);   break;
			case 2: v2.x = 0;  v2.y = rand() % (int)(visibleSize.height);;   break;
			default:v2.x = visibleSize.width; v2.y = rand() % (int)(visibleSize.height - 5);   break;
			}
			//========ȷ������===========
			//������������εĵ�
			float x1, y1, I;
			x1 = re.origin.x + rand() % (int)(re.size.width);
			y1 = re.origin.y + rand() % (int)(re.size.height);

			y1 -= v2.y; x1 -= v2.x;
			//��ȡб�߳��ȣ�
			I = H / sqrt(x1*x1 + y1*y1);
			y1 = y1*I; x1 = x1 *I;
			auto moveby = cocos2d::MoveBy::create(time, Vec2(x1, y1));
			// ��ȡ�������
			auto sp = SpriteManager::getBarrageSprite();
			// ��ʼ������
			sp->initBarrageSprite(layer, v2, moveby, 1, 50.0f, 5);
		}
	}
}

void Attack::_Practice(BarrageSprite *barr, Layer *layer, Rect re, float time) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 v2;
	//���ó�����
	switch (rand()%4)
	{
	case 0: v2.y = 0;  v2.x = rand() % (int)(visibleSize.width);   break;
	case 1: v2.y = visibleSize.height; v2.x = rand() % (int)(visibleSize.width - 5);   break;
	case 2: v2.x = 0;  v2.y = rand() % (int)(visibleSize.height);;   break;
	default:v2.x = visibleSize.width; v2.y = rand() % (int)(visibleSize.height - 5);   break;
	}
	//========ȷ������===========
	//������������εĵ�
	float x1, y1, I;
	x1 = re.origin.x + rand() % (int)(re.size.width);
	y1 = re.origin.y + rand() % (int)(re.size.height);

	y1 -= v2.y; x1 -= v2.x;
	//��ȡб�߳��ȣ�
	I = H / sqrt(x1*x1 + y1*y1);
	y1 = y1*I; x1 = x1 *I;
	auto moveby = cocos2d::MoveBy::create(time, Vec2(x1, y1));


	barr->initBarrageSprite(layer, v2, moveby, 1, 50, 5);

/*	// ��ʼ������
	barr->Effective = true;
	barr->setPosition(v2);
	barr->stopAllActions();
	barr->runAction(moveby);*/
}


void Attack::Beeline(Layer *layer, int owner, Vec2 xy, float direction, int type, int tiem, float attackStrength) {
	Size visibleSize = Director::getInstance()->getVisibleSize();

	float b = direction*M_PI / 180;//������䷽��Ļ���
	//ȷ������
	auto moveby = cocos2d::MoveBy::create(tiem, Vec2(/*H*cos(b)*/0.0f, H*sin(b)));
	// ��ȡ�������
	auto sp = SpriteManager::getBarrageSprite();
	// ��ʼ������
	sp->initBarrageSprite(layer, xy, moveby, owner, 40.0f*attackStrength, type);
}

//Բ�ε�Ļ
//ͼ�㣬�����ߣ�0��1����xy,�������� ��Χ����Ļ���ͣ�ʱ�䣬����ǿ��(�˺�)
void Attack::yuan(Layer *layer, int owner, Vec2 xy, float direction, int shuliang, double huxingchangdu, int type, int time, float attackStrength){
	//a��ʼ�Ƕ�a1�Ƕȼ��b����
	double a, a1, b;
	a = direction - huxingchangdu*0.5;
	a1 = huxingchangdu / (shuliang-1);

	for (int i = 0; i < shuliang; i++)
	{
		//========ȷ������===========
		b = (i*a1 + a)*M_PI / 180;//�������
		//	sin(b);//�������
		//	cos(b);//�������	
		auto moveby = cocos2d::MoveBy::create(time, Vec2(H*cos(b), H*sin(b)));
		// ��ȡ�������
		auto sp = SpriteManager::getBarrageSprite();
		// ��ʼ������
		sp->initBarrageSprite(layer, xy, moveby, owner, 10.0f*attackStrength, type);
	}
}



