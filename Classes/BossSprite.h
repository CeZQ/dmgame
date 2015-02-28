#ifndef __BossSprite__
#define __BossSprite__

#include "CharacterSprite.h"

class BossSprite : public CharacterSprite
{
public:
	BossSprite();
	~BossSprite();


	void initBossSprite(const char * xmlPath);
	
	
	int z;
	
	void gongji(Layer *layer);


	void gj0();
	void gj1();
	void gj2();
	void gj3();



	std::string HeadImage[11];

private:

};




#endif