#ifndef __GameMessage__
#define __GameMessage__

#include "cocos2d.h"

USING_NS_CC;

/*
	游戏消息类
	主要负责在游戏中弹窗
*/
class GameMessage
{
public:
	GameMessage();
	~GameMessage();


	// 实例方法  根据参数设定弹窗内容     并且显示出来    创建对象需要保存至ve
	static	void newGameMessage(Layer *layer, const std::string title, const std::string message, std::map<std::string, ccMenuCallback> map);
	// layer  图层
	// title  标题
	// message 消息内容
	// map   key值为按钮文本    value值为按钮回调函数

	// 保存对象
	//	Vector<Node *> ve;

	// 从图层layer 释放ve所有对象
	static	void remove(Layer *layer);


private:

};



#endif