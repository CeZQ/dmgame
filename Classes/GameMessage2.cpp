#include "GameMessage2.h"
#include "KeyMessages.h"

#include "TextUTF8.h"

GameMessage2::GameMessage2()
{
}

GameMessage2::~GameMessage2()
{
}

void GameMessage2::newGameMessage(Layer *layer, const char * title, const std::string message, std::map<std::string, ccMenuCallback> mymap, const std::string path) {
	KeyMessages::PR();


	if (layer->getChildByTag(1000))return;
	Size visibleSize = layer->getBoundingBox().size;
	Vec2 origin = layer->getBoundingBox().origin;
	log("%f,%f",origin.x, origin.y);
	log("%f,%f", visibleSize.width, visibleSize.height);
	//底层背景
	auto bj = Sprite::create(path);
	bj->setAnchorPoint(Vec2(0, 0));
	bj->setPosition(0,0);
	bj->setTag(1004);
	layer->addChild(bj, 1000);


	//标题
//	auto label = LabelTTF::create(TextUTF8::getCStringForKey("tuichu"), "Marker Felt", 32);
	auto label = Label::create(title, "Marker Felt", 40);
	label->setColor(Color3B::BLACK);
	label->setAnchorPoint(Vec2(0.5, 0));
	label->setPosition(615 , 280);
	label->setTag(1005);
	layer->addChild(label, 1001);

	//消息
	auto label1 = Label::create(message, "Marker Felt", 28);
	label1->setColor(Color3B::BLACK);
	label1->setAnchorPoint(Vec2(0.5, 1));
	label1->setPosition(615 , 270 );
	label1->setTag(1006);
	layer->addChild(label1, 1000);

	//按钮
	std::map<std::string, ccMenuCallback>::iterator l;
	l = mymap.begin();
	MenuItemLabel *anniu[4];
	for (int i = 0; l != mymap.end(); i++){

		auto label = Label::create(l->first, "Marker Felt", 30);
		label->setColor(Color3B::BLACK);
		anniu[i] = MenuItemLabel::create(label, l->second);
		l++; 
		//计算坐标
		anniu[i]->setAnchorPoint(Vec2(0, 0));
		anniu[i]->setPosition(400 +120*i, 60);

		

		//layer->addChild(anniu[i], 1000);
	}/**/
	Menu *menu;

	switch (mymap.size())
	{
		case 4:	menu = Menu::create(anniu[0], anniu[1], anniu[2], anniu[3], NULL); break;
		case 1:	menu = Menu::create(anniu[0],  NULL); break;
		case 2:	menu = Menu::create(anniu[0], anniu[1],  NULL); break;
		default:	menu = Menu::create(anniu[0], anniu[1], anniu[2], NULL);
			break;
	}
	menu->setTag(1007);
	menu->setPosition(Vec2::ZERO);
	layer->addChild(menu, 1000);
	
}
void GameMessage2::remove(Layer *layer){
	KeyMessages::PR();

	if (layer->getChildByTag(1004) == NULL)return;
	for (int i = 0; i < 4; i++){
		layer->removeChildByTag(1004 + i, 0);
	}

}