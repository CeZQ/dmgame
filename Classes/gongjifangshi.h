

#include "cocos2d.h"
#include <list>
#include "danmuci.h"
//��Ļ�ķ��г��ȣ����ó����
#define H 1700
//���Ƕ�����ô���ľ��룬�ٶ���ʱ�����  �����Ҳ��һ���ģ�
//  ���� �ﵽЧ������ ��~  ��û������~ 
// �ҿ���������μ���� ~
// �ð� �ҵ��뷨�Ǽ����ƶ�����  Ȼ����ÿ������ƶ��ľ���   Ȼ�����ʱ��  �����Ϳ��Ա��ֲ�ͬ���� �ٶ�һ�� 
#define S 2

using namespace cocos2d;

//ʹ��˵���� ��һ��������ʼ�����ڶ�����Ҫ��ʾ��ͼ�㸳ֵ��

//���ǿ����Զ����յ�Ļ�ˣ������ڹ��캯�����������߳�ѭ����Ļ���պ���

//���պ�������ײ������δ����

class gongjifangshi
{
public:
	cocos2d::Layer *layer;//Ҫ��ʾ����ͼ��ָ��  
	
	gongjifangshi();
	~gongjifangshi();

	//��Ļ���鲢û�и��ݷ�����ת����ʱ��Ľ�

	//ֱ�ߵ�Ļ//�����ߣ��������꣬��ʾ����01234�������ң���ʾ����,��ʾ��࣬��Ļ��ʽ������ʱ�䣨ԽСԽ�죩
//	void zhixian(int gjz, Vec2 x, int fanxiang, int geshu, float jianju, int yangshi, float shijian);

	//ֱ�ߵ�Ļ2//�����ߣ��������꣬��ʾ����0��360������ʾ����,��ʾ��࣬��Ļ��ʽ������ʱ�䣨ԽСԽ�죩
	void zhixian2_0(int gjz, Vec2 x, double fanxiang, int geshu, float jianju, int yangshi, float shijian);

	//Բ�ε�Ļ//�����ߣ��������꣬�ܶ�(��������ܶȵ�4��)����ʽ������ʱ�䣨ԽСԽ�죩
	void yuan(int gjz, Vec2 x, int midu, int yangshi,float shijian);

	//���ε�Ļ//�����ߣ��������꣬���������䷽��0-360�������γ��ȣ�0-360������ʽ������ʱ�䣨ԽСԽ�죩
	void huxing(int gjz, Vec2 x, int geshu, double fangxiang, double huxingchangdu, int yangshi, float shijian);


	//��������㣬ָ����������Ļ//�����ߣ�������ָ�����Σ���ʽ������ʱ�䣨ԽСԽ�죩
	void quanping1(int gjz, int geshu, Rect rt, int yangshi, float shijian);

private:

	

	//��Ļ��ʽѡ��1��ɫ10*10Բ�㣬����10*10���
	Sprite* yangshixuanzhe(int yangshi);
	danmuci* dmc;

  
  Texture2D*  texture[S];//����2d���� 
  
};

