#ifndef __BarrageSprite__
#define __BarrageSprite__

#include "BaseSprite.h"


/*
	����ǵ�Ļ��  �̳����Զ��徫����


*/
class BarrageSprite : public BaseSprite
{
public:
	BarrageSprite();
	~BarrageSprite();

	// ͼ�� ��ʼ���� �ƶ����� ��Ļ������ ��Ļ�˺� ��Ļ��Դ����
	void initBarrageSprite(Layer *layer, Vec2 v2, Action *move, int owner, float hurt, int resourceType);


	/*
		����Ļ��ֱ�ӱ����Ч     Ȼ�������߳�
		��ײ������ײ  Ȼ�������߳�����ײ��������   Ȼ���ٱ����Ч
	*/
	bool Collision;			// ��ײ���
	void Collision_Fun();	// ��ײ������  �������֮����Ҫ���Ϊ��Ч


	bool Effective;		// ������Ч���ֵ����ʼΪtrue
	bool isEffective();	// ����Ƿ���Ч


	bool VX;

	void Recover(Layer *layer);		// ��Чʱ���յ�Ļ  ��Ҫ�����̵߳���   
	

	int Owner;			// ��Ļ���з�  0��� 1�з�
	float Hurt;			// ��Ļ�˺�
private:
};




#endif