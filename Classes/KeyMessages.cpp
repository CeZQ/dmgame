#include "KeyMessages.h"

#include <Windows.h>
#include <process.h>
#include <cstdio>


#include "SpriteManager.h"

#include "DMGameControl.h"


USING_NS_CC;

KeyMessages * KeyMessages::keyMessages = NULL;

bool KeyMessages::start = true;

KeyMessages::KeyMessages()
{
	run = true;
//	KeyB = true;
	h = GetForegroundWindow();


	// WASD
	keyMsg.insert(pair<int, string>(65, ""));
	keyMsg.insert(pair<int, string>(68, ""));
	keyMsg.insert(pair<int, string>(83, ""));
	keyMsg.insert(pair<int, string>(87, ""));

	// ESC
	keyMsg.insert(pair<int, string>(27, ""));

	// 攻击 I
	keyMsg.insert(pair<int, string>(73, ""));

	// 技能
	keyMsg.insert(pair<int, string>(VK_UP, ""));
}

KeyMessages::~KeyMessages()
{
	// 释放内存
}

KeyMessages *KeyMessages::getKeyMessages() {
	if (!keyMessages)
	{
		keyMessages = new KeyMessages;
	}
	return keyMessages;
}

void KeyMessages::CreateKeyMessageReceived() {
	// 线程接收按键消息

	
//	KeyMessages::hThrd = CreateThread(NULL, 0, LPTHREAD_START_ROUTINE(ReceiveKeyMessages), NULL, 0, &KeyMessages::threadID);

	KeyMessages::start = false;
	_beginthreadex(NULL, 0, ReceiveKeyMessages, NULL, 0, NULL);
	
}

unsigned int __stdcall KeyMessages::ReceiveKeyMessages(void *p)
//void WINAPI KeyMessages::ReceiveKeyMessages(void *p) 
{
	log("aaaaaaaaaaaaaaaaaaaaaaa");

	auto keymsg = KeyMessages::getKeyMessages()->keyMsg;
	map < int, string >::iterator iter;

	while (true)
	{
		if (KeyMessages::start)
		{
			Vec2 v2 = Vec2::ZERO;
			HWND _h = GetForegroundWindow();
			if (_h == KeyMessages::getKeyMessages()->h)
			{
				for (iter = keymsg.begin(); iter != keymsg.end(); iter++)
				{
					if (GetAsyncKeyState(iter->first))
					{
					//	KeyMessages::getKeyMessages()->KeyB = false;
						float n = 4.0f * SpriteManager::getSpriteManager()->playerSprite->Speed;
						switch (iter->first)
						{
							// 上下左右
						case 87:
							v2.y += n;
							break;
						case 83:
							v2.y -= n;
							break;
						case 65:
							v2.x -= n;
							break;
						case 68:
							v2.x += n;
							break;


							// ESC
						case 27:
							KeyMessages::PR();
							break;


							// 攻击 I
						case 73:
							
							if (KeyMessages::getKeyMessages()->i >= 40)
							{
								log("I");
								SpriteManager::getSpriteManager()->playerSprite->Attack_I = !SpriteManager::getSpriteManager()->playerSprite->Attack_I;
								KeyMessages::getKeyMessages()->i = 0;
							}
							break;
						case VK_UP:
							if (KeyMessages::getKeyMessages()->i >= 40)
							{
								log("UP");
								SpriteManager::getSpriteManager()->playerSprite->Attack_O = true;
								KeyMessages::getKeyMessages()->i = 0;
							}
							break;

							
						default:
							break;

							// J
							// K
							// L
							// I
							// O
						}
						//NotificationCenter::getInstance()->postNotification(iter->second, i);
					}
				}
				KeyMessages::getKeyMessages()->ve = v2;
			}
			else {
				log("NO");
				//DMGameControl::getDMGameControl()->stopAllActions();
	//			Director::getInstance()->stopAnimation();
			//	SetForegroundWindow(KeyMessages::getKeyMessages()->h);
				Sleep(400);
			}
			++KeyMessages::getKeyMessages()->i;
		}
		else {
			Sleep(100);
			log("keyMessages");
		}
		
		Sleep(30);
	}
//	return 0;
}


bool KeyMessages::BindingMessageHandler(cocos2d::Ref *target, cocos2d::SEL_CallFuncO selector, const int key, const std::string &name) {

	// 按键消息处理
	NotificationCenter::getInstance()->addObserver(target, selector, name, NULL);
	keyMsg.insert(pair<int, string>(key, name));

	
	return 0;
}


void KeyMessages::PR() {
	if (KeyMessages::getKeyMessages()->run) {
		log("pause");

		DMGameControl::getDMGameControl()->dmGameView->pauseSchedulerAndActions();
		SpriteManager::pauseBarrage();
		DMGameControl::getDMGameControl()->gameBackgroundView->pauseSchedulerAndActions();

		KeyMessages::getKeyMessages()->run = false;
		Sleep(500);
	}
	else {
		log("resume");
		Sleep(500);
		DMGameControl::getDMGameControl()->dmGameView->resumeSchedulerAndActions();
		SpriteManager::resumeBarrage();
		DMGameControl::getDMGameControl()->gameBackgroundView->resumeSchedulerAndActions();

		KeyMessages::getKeyMessages()->run = true;

	}
}