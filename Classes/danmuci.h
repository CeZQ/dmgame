


//��Ļ��
#include <list>
#include "DanMu.h"
//���ճش�С
#define H 1000

class danmuci
{
public:
	
	static danmuci* Getdmc();//��������(�������ʵ��)  

	std::list<DanMu> ci1,ci2;//����������Ļ�ϵĵ�Ļ
	
	cocos2d::Layer *layer;//Ҫ��ʾ����ͼ��ָ��  �������ٶ��൯Ļ
	//����ָ��������Ļ����������
	std::list<DanMu> chongyong(int n);

	//��ci1�����Ѿ��ܳ���Ļ��ĵ�Ļ����ci2
	void  zidonghuishou();
	//�ֶ�����(�����Ǹ�������)
	void  huishou(std::list<DanMu>::iterator l);

	~danmuci();

private:
	
	danmuci();
};

