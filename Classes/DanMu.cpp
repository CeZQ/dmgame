


#include "DanMu.h"

DanMu::DanMu(){

}

DanMu::~DanMu()
{
	//log("dele");
}
DanMu::DanMu(int sx, int s,Sprite *sprite){
	dmsx = sx; 
	syz = s;
	danmu = sprite;
}

DanMu* DanMu::init(int sx, int s, Sprite *sprite){
	dmsx = sx;
	syz = s;
	danmu = sprite;
	return this;
}

bool DanMu::pengzhuang(Rect r){
	int x, y, w, h, X, Y, W, H;
	X = r.origin.x; Y = r.origin.y;
	W = r.size.width; H = r.size.height;
	//��õ�Ļ�ĸ߿�
	h = danmu->getTexture()->getPixelsHigh()*danmu->getScaleY();
	w = danmu->getTexture()->getPixelsWide()*danmu->getScaleX();
	//����
	Vec2 v = danmu->getPosition();
	x = v.x; y = v.y;

	//�ж�
		//�ж�x���Ƿ��ཻ
	if ((x < X&&X < x + w) ||(X<x&&x<X+W) ){
		//�ж�y���Ƿ��ཻ
		if ((y < Y&&Y < y + h) && (Y < y && y < Y + H))
		{
			log("zhuangle"); return 1;
		}
	}


	return false;
}
bool DanMu::yaoyong(){
	Size size = Director::getInstance()->getWinSize();
	Vec2 v = danmu->getPosition();
	if (v.x> size.width || v.y > size.height||v.x<0||v.y<0)
	{
		return false; log("�õ�Ļ������");
	}
	else
	{
		 return 1;log("�õ�Ļ����");

	}
}