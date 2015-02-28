#include "TextUTF8.h"

USING_NS_CC;

cocos2d::Dictionary *TextUTF8::dic = NULL;

TextUTF8::TextUTF8()
{
}

TextUTF8::~TextUTF8()
{
}


const char * TextUTF8::getCStringForKey(const std::string &key) {
//	if (!dic)
	{
		dic = Dictionary::createWithContentsOfFile("Text_CN.xml");
		dic->setObject(String::create("ass"), "MAX");
		dic->writeToFile("xyz.xml");
	}
	return ((String *)dic->objectForKey(key))->getCString();
}