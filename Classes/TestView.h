#ifndef __TEST__
#define __TEST__

#include "cocos2d.h"
#include "gongjifangshi.h"


USING_NS_CC;
/*
	这个类主要用于测试界面相关程式是否无误

*/

class TestView : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TestView);


	// 加血 减血   
	// 发现： 如果在上次动画未结束的时候执行下个动画   会以第二次执行时血量为基准 来进行下次动画
	// 也就是说  初始100  第一次 -40  执行到一半的时候   再执行-40  实际结果为 100 -20 -40
	void bu1(Ref* pSender);
	void hpadd(Ref* pSender);



	// 测试弹幕
	cocos2d::Sprite *sp;
	void DMTest(Ref* pSender);

	// 测试键盘消息
	void keymsg(float f);
private:
	gongjifangshi gj;
};





#endif