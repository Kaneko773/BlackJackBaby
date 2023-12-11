#pragma once

class Shoe;
#include "Card.h"

class Person
{
private:
	Card _hand[16];	// ��D���
	int _cardNum;	// ��D�̖���

	char* _pName;	// ���O

public:
	Person(const char* pName);
	virtual ~Person();

	void hit(Shoe* shoe);	// �V���[����P���Ђ�

	void showHand();	// ��D��\��
	void showOneCard(int num); //1���\��

	int calcScore();	// �X�R�A���v�Z���ĕԂ�

	const char* getName() const;
	const int get_cardNum() const;

	virtual bool playBase(Shoe* pShoe) = 0;
	bool play(Shoe* pShoe);
};
