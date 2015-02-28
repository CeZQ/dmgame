#ifndef __SelectLevelView__
#define __SelectLevelView__

#include "cocos2d.h"

USING_NS_CC;

class SelectLevelView : public cocos2d::Layer
{
public:
	SelectLevelView();
	~SelectLevelView();

	static cocos2d::Scene* createScene();
	virtual bool init();
	
	CREATE_FUNC(SelectLevelView);

	void SelectItem(Ref *ref);

	static int selectX;
	void selectGK(float f);

private:

};




#endif