#ifndef __Attack__
#define __Attack__

#include "cocos2d.h"

#include "BarrageSprite.h"

USING_NS_CC;

/*
	������
	������ʵ�ָ��ֹ�����ʽ�ľ�̬����
*/



class Attack
{
public:
	Attack();
	~Attack();



	// ��ϰ��Ļ			ͼ�� ���� �������� ʱ��
	static void Practice(Layer *layer, int number, Rect re, float time);
	static void _Practice(BarrageSprite *barr, Layer *layer, Rect re, float time);

	// ֱ�߹���
	//ͼ�㣬�����ߣ�0��1����xy,���򣬵�Ļ���ͣ�ʱ�䣬����ǿ��(�˺�)
	static void Beeline(Layer *layer, int owner, Vec2 xy, float direction, int type, int tiem, float attackStrength);

	//Բ�ε�Ļ
	//ͼ�㣬�����ߣ�0��1����xy,������������Ļ���ͣ�ʱ�䣬����ǿ��(�˺�)
	static void yuan(Layer *layer, int owner, Vec2 xy, float direction, int shuliang, double huxingchangdu, int type, int tiem, float attackStrength);


	//��������㣬ָ����������Ļ//�����ߣ�������ָ�����Σ���ʽ������ʱ�䣨ԽСԽ�죩
//	static void quanping1(int gjz, int geshu, Rect rt, int yangshi, float shijian);


	//ֱ�ߵ�Ļ2//�����ߣ��������꣬��ʾ����0��360������ʾ����,��ʾ��࣬��Ļ��ʽ������ʱ�䣨ԽСԽ�죩
	static void zhixian2_0(int gjz, Vec2 x, double fanxiang, int geshu, float jianju, int yangshi, float shijian);




	
private:
	
};



#endif