#ifndef __BASE_SPRITE__
#define __BASE_SPRITE__

#include "cocos2d.h"

USING_NS_CC;

/*
	自定义基础精灵类
	是游戏中所有弹幕、人物的基类
	主要是实现一些它们共有的属性和方法
*/

class BaseSprite : public cocos2d::Sprite
{
public:
	BaseSprite();
	~BaseSprite();
	
	Size size;	// 体积

	// 碰撞检测 确认矩形是否和本对象重叠  
	bool isRect(const Rect re);
//	bool pengZhuang;	// 保存碰撞检测数据

private:
	// 类型
};



#endif