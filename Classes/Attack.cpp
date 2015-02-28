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
			//设置出生点
			switch (i)
			{
			case 0: v2.y = 0;  v2.x = rand() % (int)(visibleSize.width);   break;
			case 1: v2.y = visibleSize.height; v2.x = rand() % (int)(visibleSize.width - 5);   break;
			case 2: v2.x = 0;  v2.y = rand() % (int)(visibleSize.height);;   break;
			default:v2.x = visibleSize.width; v2.y = rand() % (int)(visibleSize.height - 5);   break;
			}
			//========确定动画===========
			//随机出经过矩形的点
			float x1, y1, I;
			x1 = re.origin.x + rand() % (int)(re.size.width);
			y1 = re.origin.y + rand() % (int)(re.size.height);

			y1 -= v2.y; x1 -= v2.x;
			//获取斜边长度；
			I = H / sqrt(x1*x1 + y1*y1);
			y1 = y1*I; x1 = x1 *I;
			auto moveby = cocos2d::MoveBy::create(time, Vec2(x1, y1));
			// 获取精灵对象
			auto sp = SpriteManager::getBarrageSprite();
			// 初始化精灵
			sp->initBarrageSprite(layer, v2, moveby, 1, 50.0f, 5);
		}
	}
}

void Attack::_Practice(BarrageSprite *barr, Layer *layer, Rect re, float time) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 v2;
	//设置出生点
	switch (rand()%4)
	{
	case 0: v2.y = 0;  v2.x = rand() % (int)(visibleSize.width);   break;
	case 1: v2.y = visibleSize.height; v2.x = rand() % (int)(visibleSize.width - 5);   break;
	case 2: v2.x = 0;  v2.y = rand() % (int)(visibleSize.height);;   break;
	default:v2.x = visibleSize.width; v2.y = rand() % (int)(visibleSize.height - 5);   break;
	}
	//========确定动画===========
	//随机出经过矩形的点
	float x1, y1, I;
	x1 = re.origin.x + rand() % (int)(re.size.width);
	y1 = re.origin.y + rand() % (int)(re.size.height);

	y1 -= v2.y; x1 -= v2.x;
	//获取斜边长度；
	I = H / sqrt(x1*x1 + y1*y1);
	y1 = y1*I; x1 = x1 *I;
	auto moveby = cocos2d::MoveBy::create(time, Vec2(x1, y1));


	barr->initBarrageSprite(layer, v2, moveby, 1, 50, 5);

/*	// 初始化精灵
	barr->Effective = true;
	barr->setPosition(v2);
	barr->stopAllActions();
	barr->runAction(moveby);*/
}


void Attack::Beeline(Layer *layer, int owner, Vec2 xy, float direction, int type, int tiem, float attackStrength) {
	Size visibleSize = Director::getInstance()->getVisibleSize();

	float b = direction*M_PI / 180;//算出发射方向的弧度
	//确定动画
	auto moveby = cocos2d::MoveBy::create(tiem, Vec2(/*H*cos(b)*/0.0f, H*sin(b)));
	// 获取精灵对象
	auto sp = SpriteManager::getBarrageSprite();
	// 初始化精灵
	sp->initBarrageSprite(layer, xy, moveby, owner, 40.0f*attackStrength, type);
}

//圆形弹幕
//图层，所有者（0，1），xy,方向，数量 范围，弹幕类型，时间，攻击强度(伤害)
void Attack::yuan(Layer *layer, int owner, Vec2 xy, float direction, int shuliang, double huxingchangdu, int type, int time, float attackStrength){
	//a初始角度a1角度间距b弧度
	double a, a1, b;
	a = direction - huxingchangdu*0.5;
	a1 = huxingchangdu / (shuliang-1);

	for (int i = 0; i < shuliang; i++)
	{
		//========确定动画===========
		b = (i*a1 + a)*M_PI / 180;//算出弧度
		//	sin(b);//算出正切
		//	cos(b);//算出余切	
		auto moveby = cocos2d::MoveBy::create(time, Vec2(H*cos(b), H*sin(b)));
		// 获取精灵对象
		auto sp = SpriteManager::getBarrageSprite();
		// 初始化精灵
		sp->initBarrageSprite(layer, xy, moveby, owner, 10.0f*attackStrength, type);
	}
}



