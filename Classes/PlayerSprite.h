#ifndef __PLAYER_SPRITE__
#define __PLAYER_SPRITE__

#include "CharacterSprite.h"



/*
	�����
	�̳��Խ�ɫ��
*/

class PlayerSprite : public CharacterSprite
{
public:
	PlayerSprite();
	~PlayerSprite();
	
	void initPlayerSprite(const std::string xmlPath);
	
	// ͷ��
	std::string HeadImage[11];


	// ������
	bool Attack_I;
	int Attack_I_FPS, Attack_I_FPS_;

	void Attack_I_Fun(Layer *layer);			// ��ͨ��������


	//
	bool Attack_J, Attack_K, Attack_L;

	// ����
	bool OX;
	// ʱ����ͣ
	bool Attack_O; // �ͷż���
	int Attack_O_FPS, Attack_O_FPS_;	// ��ȴʱ��
	int Attack_O_CX, Attack_O_CX_;	// ����֡
	void Attack_O_Fun();





private:

	// ������ʽ

	// ��ͨ����

	// 
};


#endif