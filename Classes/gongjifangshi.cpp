//ʹ��˵���� ��һ��������ʼ�����ڶ�����Ҫ��ʾ��ͼ�㸳ֵ��

//���ǿ����Զ����յ�Ļ�ˣ������ڹ��캯�����������߳�ѭ����Ļ���պ���

//���պ�������ײ������δ����

#include "gongjifangshi.h"
#include<cmath>


USING_NS_CC;

gongjifangshi::gongjifangshi()
{
	//	l = danmuci.begin;
	//	log("xx");
	//	texture[0] = TextureCache::sharedTextureCache()->addImage("5.png");//����2d����
	//	texture[1] = TextureCache::sharedTextureCache()->addImage("5lan.png");

	dmc = danmuci::Getdmc();
}

gongjifangshi::~gongjifangshi()
{
	srand((int)time(0));//����������ӣ���Ȼ��Ҳ��֪��ɶ��˼

}

/*
void gongjifangshi::init() {
// û����
auto sp = Sprite::create("5.png");
sp->setPosition(Vec2(500,200));
layer->addChild(sp, 0);
}
*/

/*//������,���������꣬������ʽ
void gongjifangshi::gongji(int gjz, Vec2 x, int i){
switch (i)
{
case 0: this->fangfa1(gjz, x); break;

default:this->fangfa1(gjz, x);
break;
}

}

*/

//���Է���
/*
void gongjifangshi::fangfa1(int gjz, Vec2 x){
int i = 4;
while (i--)
{
this->zhixian(gjz, x, i,2,50,1,10);
}


}
*/

//��Ļ��ʽѡ��1��ɫ10*10Բ�㣬����10*10���
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
//ֱ�ߵ�Ļ//�����ߣ��������꣬��ʾ����01234�������ң���ʾ����,��ʾ��࣬��Ļ��ʽ������ʱ�䣨ԽСԽ�죩
/*
void gongjifangshi::zhixian(int gjz, Vec2 x, int fangxiang,int geshu,float jianju,int yangshi,float shijian){

std::list<DanMu>::iterator l;//���������l
std::list<DanMu> ci;
ci = dmc->chongyong(geshu);
l = ci.begin();

Vec2 X = x;
//ȷ����Ļ
for (int i = 0; i < geshu;i++)
{

//ȷ������//���ó�����
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
//ȷ����ʽ


//	auto d = cocos2d::Sprite::createWithTexture(texture[yangshi]);
Sprite *d;
switch (yangshi)
{
case 1:d = cocos2d::Sprite::create("5lan.png");	break;
default:d = cocos2d::Sprite::create("5.png");	break;
}

d->setPosition(x);
//==============�������======

DanMu *danmu = l->init(yangshi, gjz, d); l++;
dmc->ci1.push_back(*danmu);//����������һ

danmu->danmu->runAction(moveby);
layer->addChild(d, 2);

}

}
*/


//ֱ�ߵ�Ļ2//�����ߣ��������꣬��ʾ����0��360������ʾ����,��ʾ��࣬��Ļ��ʽ������ʱ�䣨ԽСԽ�죩
void gongjifangshi::zhixian2_0(int gjz, Vec2 x, double fangxiang, int geshu, float jianju, int yangshi, float shijian){

	std::list<DanMu>::iterator l;//���������l
	std::list<DanMu> ci;
	ci = dmc->chongyong(geshu);
	l = ci.begin();

	double b = fangxiang*M_PI / 180;//������䷽��Ļ���

	double d2 = (fangxiang - 90)*M_PI / 180;//���������Ļ���
	//��������ߵĳ�����͸�������
	x.x += (geshu - 1)*jianju*cos(d2)*0.5;//ɵ�ƣ�10����Ļ��9���գ���Ҫ���飡
	x.y += (geshu - 1)*jianju*sin(d2)*0.5;
	Vec2 X = x;
	int w = jianju*cos(d2);
	int h = jianju*sin(d2);;
	//ȷ����Ļ
	for (int i = 0; i < geshu; i++)
	{
		x = X;
		//ȷ������
		auto moveby = cocos2d::MoveBy::create(shijian, Vec2(H*cos(b), H*sin(b)));

		//ȷ����ʽ
		Sprite *d = yangshixuanzhe(yangshi);

		//���ó�����
		x.x -= w*i;
		x.y -= h*i;
		d->setPosition(x);

		//��ʼ����
		d->runAction(moveby);
		layer->addChild(d, 2);

		//=========���뵯Ļ������===========
		DanMu *danmu = l->init(yangshi, gjz, d); l++;
		dmc->ci1.push_back(*danmu);

	}

}

//Բ�ε�Ļ//�����ߣ��������꣬�ܶ�*4����ʽ������ʱ��
void gongjifangshi::yuan(int gjz, Vec2 x, int midu, int yangshi, float shijian)
{
	std::list<DanMu>::iterator l;//���������l
	std::list<DanMu> ci;
	ci = dmc->chongyong(midu * 4);
	l = ci.begin();

	//a�Ƕ�b����
	double a, b;
	a = 90.0f / midu;
	for (int i = 0; i < midu * 4; i++)
	{
		//========ȷ������===========
		b = i*a*M_PI / 180;//�������
		//	sin(b);//�������
		//	cos(b);//�������	
		auto moveby = cocos2d::MoveBy::create(shijian, Vec2(H*cos(b), H*sin(b)));

		//ȷ����ʽ
		Sprite *d = yangshixuanzhe(yangshi);

		//���ó�����
		d->setPosition(x);

		//��ʼ����
		d->runAction(moveby);
		layer->addChild(d, 2);

		//=========���뵯Ļ������===========
		DanMu *danmu = l->init(yangshi, gjz, d); l++;
		dmc->ci1.push_back(*danmu);
	}

}

//���ε�Ļ//�����ߣ��������꣬���������䷽��0-360�������γ��ȣ�0-360������ʽ������ʱ��
void gongjifangshi::huxing(int gjz, Vec2 x, int geshu, double fangxiang, double huxingchangdu, int yangshi, float shijian){
	std::list<DanMu>::iterator l;//���������l
	std::list<DanMu> ci;
	ci = dmc->chongyong(geshu);//�ӵ�Ļ���ճ��л�ȡ���յĵ�Ļ����
	l = ci.begin();

	//a��ʼ�Ƕ�a1�Ƕȼ��b����
	double a, a1, b;
	a = fangxiang - huxingchangdu*0.5;
	a1 = huxingchangdu / geshu;

	for (int i = 0; i < geshu; i++)
	{
		//========ȷ������===========
		b = (i*a1 + a)*M_PI / 180;//�������
		//	sin(b);//�������
		//	cos(b);//�������	
		auto moveby = cocos2d::MoveBy::create(shijian, Vec2(H*cos(b), H*sin(b)));

		//ȷ����ʽ
		Sprite *d = yangshixuanzhe(yangshi);

		//���ó�����
		d->setPosition(x);

		//��ʼ����
		d->runAction(moveby);
		layer->addChild(d, 2);
		//=========���뵯Ļ������===========
		DanMu *danmu = l->init(yangshi, gjz, d); l++;
		dmc->ci1.push_back(*danmu);

	}

}

//��������㣬ָ����������Ļ//�����ߣ�������ָ�����Σ���ʽ������ʱ�䣨ԽСԽ�죩
void gongjifangshi::quanping1(int gjz, int geshu, Rect rt, int yangshi, float shijian){
	std::list<DanMu>::iterator l;//���������l
	std::list<DanMu> ci;
	ci = dmc->chongyong(geshu);//�ӵ�Ļ���ճ��л�ȡ���յĵ�Ļ����
	l = ci.begin();
	//��������
	Size vs = Director::getInstance()->getVisibleSize();
	Vec2 x, v2; double x1, y1, I;

	for (int i = 0; i < geshu; i++)
	{
		//ȷ����ʽ
		Sprite *d = yangshixuanzhe(yangshi);
		rand();
		//���ó�����
		switch (i % 4)
		{
		case 0: x.y = 0;  x.x = rand() % (int)(vs.width);   break;
		case 1: x.y = vs.height; x.x = rand() % (int)(vs.width - 5);   break;
		case 2: x.x = 0;  x.y = rand() % (int)(vs.height);;   break;
		default:x.x = vs.width; x.y = rand() % (int)(vs.height - 5);   break;
		}
		d->setPosition(x);
		//========ȷ������===========
		//������������εĵ�
		x1 = rt.origin.x + rand() % (int)(rt.size.width);
		y1 = rt.origin.y + rand() % (int)(rt.size.height);

		y1 -= x.y; x1 -= x.x;
		//��ȡб�߳��ȣ�
		I = H / sqrt(x1*x1 + y1*y1);

		y1 = y1*I; x1 = x1 *I;
		v2.x = 0; v2.y = 0;
		auto moveby = cocos2d::MoveBy::create(shijian, Vec2(x1, y1));
		//��ʼ����
		d->runAction(moveby);
		layer->addChild(d, 2);
		//=========���뵯Ļ������===========
		DanMu *danmu = l->init(yangshi, gjz, d); l++;
		dmc->ci1.push_back(*danmu);
	}

}