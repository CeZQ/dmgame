#include "BaseSprite.h"



BaseSprite::BaseSprite()
{
	init();
//	log("BaseSprite");
}

BaseSprite::~BaseSprite()
{
	log("~BaseSprite");
}


bool BaseSprite::isRect(const Rect r) {

	float mix, mxx, miy, mxy;
	float _mix, _mxx, _miy, _mxy;

	mix = getBoundingBox().getMinX();
	mxx = getBoundingBox().getMaxX();
	miy = getBoundingBox().getMinY();
	mxy = getBoundingBox().getMaxY();

	_mix = r.getMinX();
	_mxx = r.getMaxX();
	_miy = r.getMinY();
	_mxy = r.getMaxY();

	// x  

//	log("x=%.0fy=%.0fw=%.0fh=%.0f, x=%.0fy=%.0fw=%.0fh=%.0f", mix, mxx, miy, mxy, _mix, _mxx, _miy, _mxy);

	if ((_mix < mix && mix < _mxx) || (_mix < mxx && mxx < _mxx)){
//		log("YESx");
		if ((_miy < miy && miy < _mxy) || (_miy < mxy && mxy < _mxy)){
//			log("YESy");
			return 1;
		}
	}



	return 0;

/*	if ((_mix > mix && _mix < mxx) || (_mxx > mix && _mxx < mxx))
	{
		if ((_miy > miy && _miy < mxy) || (_mxy > miy && _mxy < mxy))
		{
			log("isRect");
			return true;
		}
	}
	return false;*/

/*	float x, y, w, h, X, Y, W, H;
	X = r.origin.x; Y = r.origin.y;
	W = r.size.width; H = r.size.height;
	//��õ�Ļ�ĸ߿�
	h = getBoundingBox().size.height;	//danmu->getTexture()->getPixelsHigh()*danmu->getScaleY();
	w = getBoundingBox().size.width;	//danmu->getTexture()->getPixelsWide()*danmu->getScaleX();
	//����
	Vec2 v = getPosition();
	x = v.x-h/2; y = v.y-h/2;
	//�ж�
	//�ж�x���Ƿ��ཻ
	if ((x < X&&X < x + w) || (X<x&&x<X + W)){
		//�ж�y���Ƿ��ཻ
		if ((y < Y&&Y < y + h) && (Y < y && y < Y + H))
		{
			log("isRect");
			return true;
		}
	}
	return false;*/
}










