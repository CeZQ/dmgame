#ifndef __TextUTF8__
#define __TextUTF8__

#include "cocos2d.h"

class TextUTF8
{
public:
	~TextUTF8();
	static const char * getCStringForKey(const std::string &key);
private:
	TextUTF8();
	static cocos2d::Dictionary *dic;
};



#endif