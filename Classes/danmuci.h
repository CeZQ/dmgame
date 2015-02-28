


//弹幕池
#include <list>
#include "DanMu.h"
//回收池大小
#define H 1000

class danmuci
{
public:
	
	static danmuci* Getdmc();//工厂方法(用来获得实例)  

	std::list<DanMu> ci1,ci2;//保存所有屏幕上的弹幕
	
	cocos2d::Layer *layer;//要显示到的图层指针  用来销毁多余弹幕
	//返回指定数量弹幕的重用容器
	std::list<DanMu> chongyong(int n);

	//把ci1里面已经跑出屏幕外的弹幕放入ci2
	void  zidonghuishou();
	//手动回收(参数是个迭代器)
	void  huishou(std::list<DanMu>::iterator l);

	~danmuci();

private:
	
	danmuci();
};

