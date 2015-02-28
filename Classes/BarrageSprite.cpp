#include "BarrageSprite.h"
#include "SpriteManager.h"

BarrageSprite::BarrageSprite()
{
//	log("BarrageSprite");
}

BarrageSprite::~BarrageSprite()
{
}


void BarrageSprite::initBarrageSprite(Layer *layer, Vec2 v2, Action *move, int owner, float hurt, int resourceType) {
	this->init();
	this->Owner = owner;
	this->Hurt = hurt;
	Effective = true;
	VX = false;

	// ���õ�Ļ��Դ
	this->setTexture(String::createWithFormat("%d.png", resourceType)->getCString());
	this->setPosition(v2);
	layer->addChild(this, 1);
	this->runAction(move);
	
	// ��ʼ�����֮�� �������Ļ������
	SpriteManager::Barrage.pushBack(this);
}

bool BarrageSprite::isEffective() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	float x, y;
	x = getBoundingBox().getMidX();
	y = getBoundingBox().getMidY();
	if (x<-100.0f || x>visibleSize.width+100.0f || y<-100.0f || y>visibleSize.height+100.0f)
	{
	//	log("isEffective false");
		Effective = false;
		return false;
	}
	return true;
}


/*
	
*/
void BarrageSprite::Collision_Fun() {

}

void BarrageSprite::Recover(Layer *layer) {
/*	if (Effective == false)
	{
		// ���������Ҫ����  
	//	log("Recover");
		this->stopAllActions();
		// 1.����ͼ���Ƴ�
		layer->removeChild(this);
		// 2.�ӵ�Ļ�������Ƴ�
	//	SpriteManager::Barrage.eraseObject(this);
		// 3.���뵽���ճ�������
	//	SpriteManager::_Barrage.pushBack(this);
	//	SpriteManager::_Barrage

		VX = true;
	}*/

	if (VX == true)
	{
		this->resumeSchedulerAndActions();
		this->stopAllActions();
		// 1.����ͼ���Ƴ�

		layer->removeChild(this);
	}
}