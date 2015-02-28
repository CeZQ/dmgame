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

	// 设置弹幕资源
	this->setTexture(String::createWithFormat("%d.png", resourceType)->getCString());
	this->setPosition(v2);
	layer->addChild(this, 1);
	this->runAction(move);
	
	// 初始化完成之后， 添加至弹幕容器中
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
		// 如果对象需要回收  
	//	log("Recover");
		this->stopAllActions();
		// 1.从视图中移除
		layer->removeChild(this);
		// 2.从弹幕容器中移除
	//	SpriteManager::Barrage.eraseObject(this);
		// 3.加入到回收池容器中
	//	SpriteManager::_Barrage.pushBack(this);
	//	SpriteManager::_Barrage

		VX = true;
	}*/

	if (VX == true)
	{
		this->resumeSchedulerAndActions();
		this->stopAllActions();
		// 1.从视图中移除

		layer->removeChild(this);
	}
}