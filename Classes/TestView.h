#ifndef __TEST__
#define __TEST__

#include "cocos2d.h"
#include "gongjifangshi.h"


USING_NS_CC;
/*
	�������Ҫ���ڲ��Խ�����س�ʽ�Ƿ�����

*/

class TestView : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();
	CREATE_FUNC(TestView);


	// ��Ѫ ��Ѫ   
	// ���֣� ������ϴζ���δ������ʱ��ִ���¸�����   ���Եڶ���ִ��ʱѪ��Ϊ��׼ �������´ζ���
	// Ҳ����˵  ��ʼ100  ��һ�� -40  ִ�е�һ���ʱ��   ��ִ��-40  ʵ�ʽ��Ϊ 100 -20 -40
	void bu1(Ref* pSender);
	void hpadd(Ref* pSender);



	// ���Ե�Ļ
	cocos2d::Sprite *sp;
	void DMTest(Ref* pSender);

	// ���Լ�����Ϣ
	void keymsg(float f);
private:
	gongjifangshi gj;
};





#endif