#ifndef __GameMessage__
#define __GameMessage__

#include "cocos2d.h"

USING_NS_CC;

/*
	��Ϸ��Ϣ��
	��Ҫ��������Ϸ�е���
*/
class GameMessage
{
public:
	GameMessage();
	~GameMessage();


	// ʵ������  ���ݲ����趨��������     ������ʾ����    ����������Ҫ������ve
	static	void newGameMessage(Layer *layer, const std::string title, const std::string message, std::map<std::string, ccMenuCallback> map);
	// layer  ͼ��
	// title  ����
	// message ��Ϣ����
	// map   keyֵΪ��ť�ı�    valueֵΪ��ť�ص�����

	// �������
	//	Vector<Node *> ve;

	// ��ͼ��layer �ͷ�ve���ж���
	static	void remove(Layer *layer);


private:

};



#endif