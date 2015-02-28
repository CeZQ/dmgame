#ifndef __KeyMessages__
#define __KeyMessages__

#include "cocos2d.h"
/*
	这个类主要是负责按键消息接收
*/
using namespace std;

class KeyMessages
{
public:
	~KeyMessages();

	// 绑定按键消息处理函数
	bool BindingMessageHandler(cocos2d::Ref *target, cocos2d::SEL_CallFuncO selector, const int key, const std::string &name);
	// 启动按键消息接收


	static void CreateKeyMessageReceived();

//	static HANDLE hThrd;
//	static DWORD threadID;
	// 接收按键消息线程
//	static void WINAPI ReceiveKeyMessages(void *p);
	static bool start;
	static unsigned int __stdcall ReceiveKeyMessages(void *p);
	
//	bool KeyB;

	cocos2d::Vec2 ve;


	// 确定当前活动窗口
	HWND h;

	// 确定当前窗口的运行情况  暂停/恢复
	bool run;
	static void PR();

	// 防止连续触发的一些按键
	int i = 0;


	map<int, string> keyMsg;


//	cocos2d::Map<int, std::string> map;
	// 获取类对象
	static KeyMessages *getKeyMessages();

private:

	KeyMessages();
	static KeyMessages * keyMessages;
};



#endif