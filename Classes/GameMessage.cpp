#include "GameMessage.h"


GameMessage::GameMessage()
{
}

GameMessage::~GameMessage()
{
}

void GameMessage::newGameMessage(Layer *layer, const std::string title, const std::string message, std::map<std::string, ccMenuCallback> mymap) {


	Size visibleSize = layer->getBoundingBox().size;
	Vec2 origin = layer->getBoundingBox().origin;
	log("%f,%f", origin.x, origin.y);
	log("%f,%f", visibleSize.width, visibleSize.height);
	//底层背景
	auto bj = Sprite::create("beijing.jpg");
	bj->setPosition(visibleSize.width / 2, visibleSize.height / 3 * 2);
	bj->setTag(1000);
	layer->addChild(bj, 1000);


	//标题
	auto label = Label::createWithTTF(title, "fonts/Marker Felt.ttf", 28);
	label->setColor(Color3B::BLACK);
	label->setAnchorPoint(Vec2(0, 0));
	label->setPosition(visibleSize.width / 3, visibleSize.height / 3 * 2 + 50);
	label->setTag(1001);
	layer->addChild(label, 1001);

	//消息
	auto label1 = Label::createWithTTF(message, "fonts/Marker Felt.ttf", 35);
	label1->setColor(Color3B::BLACK);
	label1->setAnchorPoint(Vec2(0, 1));
	label1->setPosition(visibleSize.width / 3, visibleSize.height / 3 * 2 + 50);
	label1->setTag(1002);
	layer->addChild(label1, 1000);

	//按钮
	std::map<std::string, ccMenuCallback>::iterator l;
	l = mymap.begin();
	MenuItemLabel *anniu[4];
	for (int i = 0; l != mymap.end(); i++){

		auto label = Label::createWithTTF(l->first, "fonts/Marker Felt.ttf", 20);
		label->setColor(Color3B::BLACK);
		anniu[i] = MenuItemLabel::create(label, l->second);
		l++;
		//计算坐标
		anniu[i]->setAnchorPoint(Vec2(0, 0));
		anniu[i]->setPosition(visibleSize.width / 3 + 89 * i, visibleSize.height / 3 * 2 - 85);
	}
	Menu *menu;
	switch (mymap.size())
	{
	case 4:	menu = Menu::create(anniu[0], anniu[1], anniu[2], anniu[3], NULL); break;
	case 1:	menu = Menu::create(anniu[0], NULL); break;
	case 2:	menu = Menu::create(anniu[0], anniu[1], NULL); break;
	default:	menu = Menu::create(anniu[0], anniu[1], anniu[2], NULL);
		break;
	}
	menu->setTag(1003);
	menu->setPosition(Vec2::ZERO);
	layer->addChild(menu, 1000);
}

void GameMessage::remove(Layer *layer){
	if (layer->getChildByTag(1000) == NULL)return;
	for (int i = 0; i < 4; i++){
		layer->removeChildByTag(1000 + i, 0);
	}
}