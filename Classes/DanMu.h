


#include "cocos2d.h"

using namespace cocos2d;
class DanMu
{
public:
	int dmsx;//�����Ļ������
	int syz;//�����Ļ�ķ�����
	Sprite *danmu;//��Ļ����

	bool pengzhuang(Rect r);//����Ƿ�Ӵ� ��������� 
	bool yaoyong();			//����Ƿ�Ҫ�ã��ڲ�����Ļ��
	DanMu* init(int sx, int s, Sprite *sprite);//��ʼ��

	DanMu();//������Լ�����ʱ�����㲻�ù�
	DanMu(int sx, int s,Sprite *sprite);//��Ļ������ʽ��������,�����ַ

	~DanMu();

private:
	
};