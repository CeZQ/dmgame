#ifndef __KeyMessages__
#define __KeyMessages__

#include "cocos2d.h"
/*
	�������Ҫ�Ǹ��𰴼���Ϣ����
*/
using namespace std;

class KeyMessages
{
public:
	~KeyMessages();

	// �󶨰�����Ϣ������
	bool BindingMessageHandler(cocos2d::Ref *target, cocos2d::SEL_CallFuncO selector, const int key, const std::string &name);
	// ����������Ϣ����


	static void CreateKeyMessageReceived();

//	static HANDLE hThrd;
//	static DWORD threadID;
	// ���հ�����Ϣ�߳�
//	static void WINAPI ReceiveKeyMessages(void *p);
	static bool start;
	static unsigned int __stdcall ReceiveKeyMessages(void *p);
	
//	bool KeyB;

	cocos2d::Vec2 ve;


	// ȷ����ǰ�����
	HWND h;

	// ȷ����ǰ���ڵ��������  ��ͣ/�ָ�
	bool run;
	static void PR();

	// ��ֹ����������һЩ����
	int i = 0;


	map<int, string> keyMsg;


//	cocos2d::Map<int, std::string> map;
	// ��ȡ�����
	static KeyMessages *getKeyMessages();

private:

	KeyMessages();
	static KeyMessages * keyMessages;
};



#endif