#ifndef __Attack__
#define __Attack__

#include "cocos2d.h"

#include "BarrageSprite.h"

USING_NS_CC;

/*
	攻击类
	包含了实现各种攻击方式的静态方法
*/



class Attack
{
public:
	Attack();
	~Attack();



	// 练习弹幕			图层 数量 经过矩形 时间
	static void Practice(Layer *layer, int number, Rect re, float time);
	static void _Practice(BarrageSprite *barr, Layer *layer, Rect re, float time);

	// 直线攻击
	//图层，所有者（0，1），xy,方向，弹幕类型，时间，攻击强度(伤害)
	static void Beeline(Layer *layer, int owner, Vec2 xy, float direction, int type, int tiem, float attackStrength);

	//圆形弹幕
	//图层，所有者（0，1），xy,方向，数量，弹幕类型，时间，攻击强度(伤害)
	static void yuan(Layer *layer, int owner, Vec2 xy, float direction, int shuliang, double huxingchangdu, int type, int tiem, float attackStrength);


	//无序出生点，指定经过区域弹幕//攻击者，个数，指定矩形，样式，动画时间（越小越快）
//	static void quanping1(int gjz, int geshu, Rect rt, int yangshi, float shijian);


	//直线弹幕2//攻击者，发射坐标，表示方向（0，360），表示个数,表示间距，弹幕样式，动画时间（越小越快）
	static void zhixian2_0(int gjz, Vec2 x, double fanxiang, int geshu, float jianju, int yangshi, float shijian);




	
private:
	
};



#endif