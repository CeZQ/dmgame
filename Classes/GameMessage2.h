#ifndef __GameMessage2__
#define __GameMessage2__

#include "cocos2d.h"
#include <map>
USING_NS_CC;

/*
	��Ϸ��Ϣ��
	��Ҫ��������Ϸ�е���

	��������ͣ���е�Ļ�� ͼ��DMGameView
*/
class GameMessage2
{
public:
	GameMessage2();
	~GameMessage2();


	// ʵ������  ���ݲ����趨��������     ������ʾ����    ����������Ҫ������ve
	static	void newGameMessage(Layer *layer, const char * title, const std::string message, std::map<std::string, ccMenuCallback> map, const std::string path);
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