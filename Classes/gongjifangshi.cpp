//使用说明， 第一步创建初始化，第二部把要显示的图层赋值。

//忘记开启自动回收弹幕了，明天在构造函数里面启动线程循环弹幕回收函数

//回收函数，碰撞函数还未测试

#include "gongjifangshi.h"
#include<cmath>


USING_NS_CC;

gongjifangshi::gongjifangshi()
{
	//	l = danmuci.begin;
	//	log("xx");
	//	texture[0] = TextureCache::sharedTextureCache()->addImage("5.png");//创建2d纹理
	//	texture[1] = TextureCache::sharedTextureCache()->addImage("5lan.png");

	dmc = danmuci::Getdmc();
}

gongjifangshi::~gongjifangshi()
{
	srand((int)time(0));//设置随机种子，虽然我也不知道啥意思

}

/*
void gongjifangshi::init() {
// 没问题
auto sp = Sprite::create("5.png");
sp->setPosition(Vec2(500,200));
layer->addChild(sp, 0);
}
*/

/*//发射者,攻击者坐标，攻击方式
void gongjifangshi::gongji(int gjz, Vec2 x, int i){
switch (i)
{
case 0: this->fangfa1(gjz, x); break;

default:this->fangfa1(gjz, x);
break;
}

}

*/

//调试方法
/*
void gongjifangshi::fangfa1(int gjz, Vec2 x){
int i = 4;
while (i--)
{
this->zhixian(gjz, x, i,2,50,1,10);
}


}
*/

//弹幕样式选择，1蓝色10*10圆点，其他10*10红点
Sprite* gongjifangshi::yangshixuanzhe(int yangshi){
	Sprite *d;
	switch (yangshi)
	{
	case 1:d = cocos2d::Sprite::create("5lan.png");	break;
	case 2:d = cocos2d::Sprite::create("10yellow.png"); break;
	case 3:d = cocos2d::Sprite::create("19lv.png"); break;
	case 4:d = cocos2d::Sprite::create("zi15.png"); break;
	case 5:d = cocos2d::Sprite::create("8lan.png"); break;
	case 6:d = cocos2d::Sprite::create("10hong.png"); break;
	default:d = cocos2d::Sprite::create("5.png");	break;
	}
	return d;
}
//直线弹幕//攻击者，发射坐标，表示方向01234上下左右，表示个数,表示间距，弹幕样式，动画时间（越小越快）
/*
void gongjifangshi::zhixian(int gjz, Vec2 x, int fangxiang,int geshu,float jianju,int yangshi,float shijian){

std::list<DanMu>::iterator l;//定义迭代器l
std::list<DanMu> ci;
ci = dmc->chongyong(geshu);
l = ci.begin();

Vec2 X = x;
//确定弹幕
for (int i = 0; i < geshu;i++)
{

//确定动画//设置出生点
Vec2 v;x = X;
switch (fangxiang)
{
case 1:v = Vec2(0, -H); x.x += ((geshu - 1)*0.5 - i)*jianju; break;
case 2:v = Vec2(-H, 0); x.y += ((geshu - 1)*0.5 - i)*jianju;  break;
case 3:v = Vec2(H, 0);  x.y += ((geshu - 1)*0.5 - i)*jianju;  break;
default:v = Vec2(0, H); x.x += ((geshu - 1)*0.5 - i)*jianju;
break;
}
auto moveby = cocos2d::MoveBy::create(shijian, v);
//确定样式


//	auto d = cocos2d::Sprite::createWithTexture(texture[yangshi]);
Sprite *d;
switch (yangshi)
{
case 1:d = cocos2d::Sprite::create("5lan.png");	break;
default:d = cocos2d::Sprite::create("5.png");	break;
}

d->setPosition(x);
//==============就下面的======

DanMu *danmu = l->init(yangshi, gjz, d); l++;
dmc->ci1.push_back(*danmu);//加入容器池一

danmu->danmu->runAction(moveby);
layer->addChild(d, 2);

}

}
*/


//直线弹幕2//攻击者，发射坐标，表示方向（0，360），表示个数,表示间距，弹幕样式，动画时间（越小越快）
void gongjifangshi::zhixian2_0(int gjz, Vec2 x, double fangxiang, int geshu, float jianju, int yangshi, float shijian){

	std::list<DanMu>::iterator l;//定义迭代器l
	std::list<DanMu> ci;
	ci = dmc->chongyong(geshu);
	l = ci.begin();

	double b = fangxiang*M_PI / 180;//算出发射方向的弧度

	double d2 = (fangxiang - 90)*M_PI / 180;//算出出生点的弧度
	//计算最左边的出生点和辅助变量
	x.x += (geshu - 1)*jianju*cos(d2)*0.5;//傻逼！10个弹幕！9个空！你要错几遍！
	x.y += (geshu - 1)*jianju*sin(d2)*0.5;
	Vec2 X = x;
	int w = jianju*cos(d2);
	int h = jianju*sin(d2);;
	//确定弹幕
	for (int i = 0; i < geshu; i++)
	{
		x = X;
		//确定动画
		auto moveby = cocos2d::MoveBy::create(shijian, Vec2(H*cos(b), H*sin(b)));

		//确定样式
		Sprite *d = yangshixuanzhe(yangshi);

		//设置出生点
		x.x -= w*i;
		x.y -= h*i;
		d->setPosition(x);

		//开始动画
		d->runAction(moveby);
		layer->addChild(d, 2);

		//=========加入弹幕容器池===========
		DanMu *danmu = l->init(yangshi, gjz, d); l++;
		dmc->ci1.push_back(*danmu);

	}

}

//圆形弹幕//攻击者，发射坐标，密度*4，样式，动画时间
void gongjifangshi::yuan(int gjz, Vec2 x, int midu, int yangshi, float shijian)
{
	std::list<DanMu>::iterator l;//定义迭代器l
	std::list<DanMu> ci;
	ci = dmc->chongyong(midu * 4);
	l = ci.begin();

	//a角度b弧度
	double a, b;
	a = 90.0f / midu;
	for (int i = 0; i < midu * 4; i++)
	{
		//========确定动画===========
		b = i*a*M_PI / 180;//算出弧度
		//	sin(b);//算出正切
		//	cos(b);//算出余切	
		auto moveby = cocos2d::MoveBy::create(shijian, Vec2(H*cos(b), H*sin(b)));

		//确定样式
		Sprite *d = yangshixuanzhe(yangshi);

		//设置出生点
		d->setPosition(x);

		//开始动画
		d->runAction(moveby);
		layer->addChild(d, 2);

		//=========加入弹幕容器池===========
		DanMu *danmu = l->init(yangshi, gjz, d); l++;
		dmc->ci1.push_back(*danmu);
	}

}

//弧形弹幕//攻击者，发射坐标，个数，发射方向（0-360），弧形长度（0-360），样式，动画时间
void gongjifangshi::huxing(int gjz, Vec2 x, int geshu, double fangxiang, double huxingchangdu, int yangshi, float shijian){
	std::list<DanMu>::iterator l;//定义迭代器l
	std::list<DanMu> ci;
	ci = dmc->chongyong(geshu);//从弹幕回收池中获取回收的弹幕容器
	l = ci.begin();

	//a初始角度a1角度间距b弧度
	double a, a1, b;
	a = fangxiang - huxingchangdu*0.5;
	a1 = huxingchangdu / geshu;

	for (int i = 0; i < geshu; i++)
	{
		//========确定动画===========
		b = (i*a1 + a)*M_PI / 180;//算出弧度
		//	sin(b);//算出正切
		//	cos(b);//算出余切	
		auto moveby = cocos2d::MoveBy::create(shijian, Vec2(H*cos(b), H*sin(b)));

		//确定样式
		Sprite *d = yangshixuanzhe(yangshi);

		//设置出生点
		d->setPosition(x);

		//开始动画
		d->runAction(moveby);
		layer->addChild(d, 2);
		//=========加入弹幕容器池===========
		DanMu *danmu = l->init(yangshi, gjz, d); l++;
		dmc->ci1.push_back(*danmu);

	}

}

//无序出生点，指定经过区域弹幕//攻击者，个数，指定矩形，样式，动画时间（越小越快）
void gongjifangshi::quanping1(int gjz, int geshu, Rect rt, int yangshi, float shijian){
	std::list<DanMu>::iterator l;//定义迭代器l
	std::list<DanMu> ci;
	ci = dmc->chongyong(geshu);//从弹幕回收池中获取回收的弹幕容器
	l = ci.begin();
	//辅助变量
	Size vs = Director::getInstance()->getVisibleSize();
	Vec2 x, v2; double x1, y1, I;

	for (int i = 0; i < geshu; i++)
	{
		//确定样式
		Sprite *d = yangshixuanzhe(yangshi);
		rand();
		//设置出生点
		switch (i % 4)
		{
		case 0: x.y = 0;  x.x = rand() % (int)(vs.width);   break;
		case 1: x.y = vs.height; x.x = rand() % (int)(vs.width - 5);   break;
		case 2: x.x = 0;  x.y = rand() % (int)(vs.height);;   break;
		default:x.x = vs.width; x.y = rand() % (int)(vs.height - 5);   break;
		}
		d->setPosition(x);
		//========确定动画===========
		//随机出经过矩形的点
		x1 = rt.origin.x + rand() % (int)(rt.size.width);
		y1 = rt.origin.y + rand() % (int)(rt.size.height);

		y1 -= x.y; x1 -= x.x;
		//获取斜边长度；
		I = H / sqrt(x1*x1 + y1*y1);

		y1 = y1*I; x1 = x1 *I;
		v2.x = 0; v2.y = 0;
		auto moveby = cocos2d::MoveBy::create(shijian, Vec2(x1, y1));
		//开始动画
		d->runAction(moveby);
		layer->addChild(d, 2);
		//=========加入弹幕容器池===========
		DanMu *danmu = l->init(yangshi, gjz, d); l++;
		dmc->ci1.push_back(*danmu);
	}

}