#include "danmuci.h"


danmuci::danmuci()
{
	
}

static danmuci* dmc = NULL;//Ωһʵ��

danmuci* danmuci::Getdmc()
{
	 if(dmc == NULL)  //�ж��Ƿ��һ�ε���  
         dmc = new danmuci();  
       
	 return dmc;  

}
danmuci::~danmuci()
{
}

void  danmuci::zidonghuishou()
{//����Ļ��

	std::list<DanMu>::iterator l;//���������l
	l = ci1.begin();
	
	while (l != ci1.end())
	{
		if (l->yaoyong()){
			l++;
		}
		else{
			//������ճ����ˣ��Ͱѵ�Ļ����
			if (ci2.size() > H){
				layer->removeChild(l->danmu);//��������Ϸ�������
				l->~DanMu();//���ٸõ�Ļ
			}
			else{
				ci2.push_back(*l);//��������//����ض�
			}
			
			l = ci1.erase(l);//�ӳ�һɾ��
		}
	}
	//�鿴
	log("%i", ci1.size());

}

void danmuci::huishou(std::list<DanMu>::iterator l){
	//������ճ����ˣ��Ͱѵ�Ļ����
	if (ci2.size() > H){
		layer->removeChild(l->danmu);//��������Ϸ�������
		l->~DanMu();//���ٸõ�Ļ
	}
	else{
		ci2.push_back(*l);//��������//����ض�
	}
	l = ci1.erase(l);//�ӳ�һɾ��
}
//���ôӻ��ճ�ȡ����
std::list<DanMu> danmuci::chongyong(int n){
	std::list<DanMu> ci;
	std::list<DanMu>::iterator l;//���������l
	l = ci2.begin();

	while (l != ci2.end())
	{
		if (n--){
			ci.push_back(*l);//���뷵������
			l = ci1.erase(l);//�ӻ��ճ�ɾ��
		}
		else
		{
			return ci;
		}
	}

	while (n--)
	{
		auto dm = DanMu();
		ci.push_front(dm);//���뷵������
		
	}
	return ci;
}