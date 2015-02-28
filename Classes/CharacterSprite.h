#ifndef __CHARACTER_SPRITE__
#define __CHARACTER_SPRITE__


#include "BaseSprite.h"

/*
	��ɫ�࣬�̳�������������
	ʵ�ֽ�ɫ���е����Է���
*/

class CharacterSprite : public BaseSprite
{
public:
	CharacterSprite();
	~CharacterSprite();


	void initCharacterSprite(Dictionary *dic);
	

	float HP;				// ����ֵ
	float HP_Change;		// ����ֵ�仯

	float MAXHP;			// �������ֵ
	float Speed;			// �ٶ�
	float AttackStrength;	// ����ǿ��

private:

};





#endif