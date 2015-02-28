


#include "cocos2d.h"

using namespace cocos2d;
class DanMu
{
public:
	int dmsx;//这个弹幕的属性
	int syz;//这个弹幕的发射者
	Sprite *danmu;//弹幕精灵

	bool pengzhuang(Rect r);//检测是否接触 该人物矩形 
	bool yaoyong();			//检测是否要用，在不在屏幕类
	DanMu* init(int sx, int s, Sprite *sprite);//初始化

	DanMu();//这个我自己攻击时调用你不用管
	DanMu(int sx, int s,Sprite *sprite);//弹幕属性样式，所有者,精灵地址

	~DanMu();

private:
	
};