#include "SelectLevelView.h"

#include "TextUTF8.h"

#include "DMGameControl.h"

int SelectLevelView::selectX = 0;

SelectLevelView::SelectLevelView()
{
}

SelectLevelView::~SelectLevelView()
{
}
cocos2d::Scene* SelectLevelView::createScene() {
	auto scene = Scene::create();
	auto layer = SelectLevelView::create();
	scene->addChild(layer, 0);
	return scene;
}

bool SelectLevelView::init() {
	if (!Layer::init())
	{
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto sprite = Sprite::create("bilibilier.jpg");
	sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(sprite, 0);


	float x = 700, y = 400;


	//TextUTF8::getCStringForKey("cundang")

	// 第一关
	auto label1 = LabelTTF::create("Level1", "Marker Felt", 32);
	label1->setHorizontalAlignment(TextHAlignment::CENTER);
	label1->setColor(Color3B::BLACK);
	auto Level1 = MenuItemLabel::create(label1, CC_CALLBACK_1(SelectLevelView::SelectItem, this));
	Level1->setPosition(Vec2(x, y + 0));
	Level1->setTag(7001);

	// 第二关
	auto label2 = LabelTTF::create("Level2", "Marker Felt", 32);
	label2->setHorizontalAlignment(TextHAlignment::CENTER);
	label2->setColor(Color3B::BLACK);
	auto Level2 = MenuItemLabel::create(label2, CC_CALLBACK_1(SelectLevelView::SelectItem, this));
	Level2->setPosition(Vec2(x, y - 60));
	Level2->setTag(7002);



	auto labelx = LabelTTF::create("tuichu", "Marker Felt", 32);
	labelx->setHorizontalAlignment(TextHAlignment::CENTER);
	labelx->setColor(Color3B::BLACK);
	auto Levelx = MenuItemLabel::create(labelx, CC_CALLBACK_1(SelectLevelView::SelectItem, this));
	Levelx->setPosition(Vec2(x, y - 200));
	Levelx->setTag(7100);


	auto menu = Menu::create(Level1, Level2, Levelx, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	
	schedule(schedule_selector(SelectLevelView::selectGK));

	return true;
}

void SelectLevelView::SelectItem(Ref *ref) {
	auto mil = (MenuItemLabel *)ref;

	log("%d", mil->getTag());

	if (mil->getTag() == 7100)
	{	
		Director::getInstance()->popScene();
	}
	else {
		auto scene = DMGameControl::newDMGameControl();
		scene->initDM(mil->getTag());
		Director::getInstance()->pushScene(scene);
	}
	
	
}

void SelectLevelView::selectGK(float f) {
	if (selectX != 0)
	{
		auto scene = DMGameControl::newDMGameControl();
		scene->initDM(selectX);
		Director::getInstance()->pushScene(scene);
	}
}
