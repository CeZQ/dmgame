

#include "cocos2d.h"
#include <list>
#include "danmuci.h"
//弹幕的飞行长度，设置成最长。
#define H 1700
//他们都跑这么长的距离，速度由时间决定  我这个也是一样的，
//  嗯嗯 达到效果就行 、~  那没问题了~ 
// 我看看你是如何计算的 ~
// 好吧 我的想法是计算移动距离  然后传入每秒可以移动的距离   然后计算时间  这样就可以报持不同距离 速度一样 
#define S 2

using namespace cocos2d;

//使用说明， 第一步创建初始化，第二部把要显示的图层赋值。

//忘记开启自动回收弹幕了，明天在构造函数里面启动线程循环弹幕回收函数

//回收函数，碰撞函数还未测试

class gongjifangshi
{
public:
	cocos2d::Layer *layer;//要显示到的图层指针  
	
	gongjifangshi();
	~gongjifangshi();

	//弹幕精灵并没有根据方向旋转，有时间改进

	//直线弹幕//攻击者，发射坐标，表示方向01234上下左右，表示个数,表示间距，弹幕样式，动画时间（越小越快）
//	void zhixian(int gjz, Vec2 x, int fanxiang, int geshu, float jianju, int yangshi, float shijian);

	//直线弹幕2//攻击者，发射坐标，表示方向（0，360），表示个数,表示间距，弹幕样式，动画时间（越小越快）
	void zhixian2_0(int gjz, Vec2 x, double fanxiang, int geshu, float jianju, int yangshi, float shijian);

	//圆形弹幕//攻击者，发射坐标，密度(发射的是密度的4倍)，样式，动画时间（越小越快）
	void yuan(int gjz, Vec2 x, int midu, int yangshi,float shijian);

	//弧形弹幕//攻击者，发射坐标，个数，发射方向（0-360），弧形长度（0-360），样式，动画时间（越小越快）
	void huxing(int gjz, Vec2 x, int geshu, double fangxiang, double huxingchangdu, int yangshi, float shijian);


	//无序出生点，指定经过区域弹幕//攻击者，个数，指定矩形，样式，动画时间（越小越快）
	void quanping1(int gjz, int geshu, Rect rt, int yangshi, float shijian);

private:

	

	//弹幕样式选择，1蓝色10*10圆点，其他10*10红点
	Sprite* yangshixuanzhe(int yangshi);
	danmuci* dmc;

  
  Texture2D*  texture[S];//返回2d纹理 
  
};

