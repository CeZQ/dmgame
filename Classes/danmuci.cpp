#include "danmuci.h"


danmuci::danmuci()
{
	
}

static danmuci* dmc = NULL;//惟一实例

danmuci* danmuci::Getdmc()
{
	 if(dmc == NULL)  //判断是否第一次调用  
         dmc = new danmuci();  
       
	 return dmc;  

}
danmuci::~danmuci()
{
}

void  danmuci::zidonghuishou()
{//管理弹幕池

	std::list<DanMu>::iterator l;//定义迭代器l
	l = ci1.begin();
	
	while (l != ci1.end())
	{
		if (l->yaoyong()){
			l++;
		}
		else{
			//如果回收池满了，就把弹幕销毁
			if (ci2.size() > H){
				layer->removeChild(l->danmu);//消掉在游戏层的引用
				l->~DanMu();//销毁该弹幕
			}
			else{
				ci2.push_back(*l);//加入容器//加入池二
			}
			
			l = ci1.erase(l);//从池一删除
		}
	}
	//查看
	log("%i", ci1.size());

}

void danmuci::huishou(std::list<DanMu>::iterator l){
	//如果回收池满了，就把弹幕销毁
	if (ci2.size() > H){
		layer->removeChild(l->danmu);//消掉在游戏层的引用
		l->~DanMu();//销毁该弹幕
	}
	else{
		ci2.push_back(*l);//加入容器//加入池二
	}
	l = ci1.erase(l);//从池一删除
}
//重用从回收池取出，
std::list<DanMu> danmuci::chongyong(int n){
	std::list<DanMu> ci;
	std::list<DanMu>::iterator l;//定义迭代器l
	l = ci2.begin();

	while (l != ci2.end())
	{
		if (n--){
			ci.push_back(*l);//加入返回容器
			l = ci1.erase(l);//从回收池删除
		}
		else
		{
			return ci;
		}
	}

	while (n--)
	{
		auto dm = DanMu();
		ci.push_front(dm);//加入返回容器
		
	}
	return ci;
}