#ifndef __BarrageSprite__
#define __BarrageSprite__

#include "BaseSprite.h"


/*
	这个是弹幕类  继承自自定义精灵类


*/
class BarrageSprite : public BaseSprite
{
public:
	BarrageSprite();
	~BarrageSprite();

	// 图层 初始坐标 移动坐标 弹幕所有者 弹幕伤害 弹幕资源类型
	void initBarrageSprite(Layer *layer, Vec2 v2, Action *move, int owner, float hurt, int resourceType);


	/*
		出屏幕会直接标记无效     然后在主线程
		碰撞会标记碰撞  然后再主线程做碰撞动画处理   然后再标记无效
	*/
	bool Collision;			// 碰撞标记
	void Collision_Fun();	// 碰撞处理函数  处理完成之后需要标记为无效


	bool Effective;		// 保存有效检测值，初始为true
	bool isEffective();	// 检测是否有效


	bool VX;

	void Recover(Layer *layer);		// 无效时回收弹幕  需要在主线程调用   
	

	int Owner;			// 弹幕所有方  0玩家 1敌方
	float Hurt;			// 弹幕伤害
private:
};




#endif