#ifndef __BASE_SPRITE__
#define __BASE_SPRITE__

#include "cocos2d.h"

USING_NS_CC;

/*
	�Զ������������
	����Ϸ�����е�Ļ������Ļ���
	��Ҫ��ʵ��һЩ���ǹ��е����Ժͷ���
*/

class BaseSprite : public cocos2d::Sprite
{
public:
	BaseSprite();
	~BaseSprite();
	
	Size size;	// ���

	// ��ײ��� ȷ�Ͼ����Ƿ�ͱ������ص�  
	bool isRect(const Rect re);
//	bool pengZhuang;	// ������ײ�������

private:
	// ����
};



#endif