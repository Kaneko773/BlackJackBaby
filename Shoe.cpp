#include <iostream>
#include "Shoe.h"

using namespace std;

// �R���X�g���N�^
Shoe::Shoe()
{
	_cardNum = CARD_NUM;	//�J�[�h����������
	// �J�[�h������
	int i = 0;
	for (int j = 0; j < MARK_NUM; ++j)
	{
		for (int k = 0; k < NUMBER_NUM; ++k) {
			_cardShoe[i].set_mark(j);
			_cardShoe[i].set_number(k);
			++i;
		}
	}

	_shuffle();	// �V���b�t������
}

Shoe::~Shoe()
{

}

//�V���b�t���i�t�B�b�V���[�C�F�[�c�j
void Shoe::_shuffle()
{
	for (int i = _cardNum; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_cardShoe[a], _cardShoe[b]);
	}
}

// �J�[�h���Ȃ��ꍇ��-1��Ԃ��܂��B
Card Shoe::takeCard()
{
	Card noncard;//�}�[�N�A�������� -1 �������Ă�J�[�h
	// ��납������Ă��������W�b�N�I�Ɋy���񂩂ƁB
	if (_cardNum <= 0) return noncard;
	_cardNum--;
	Card card = _cardShoe[_cardNum];
	_cardShoe[_cardNum] = noncard;	// �O�̂��߂���Ƃ��i�f�o�b�O�p�j

	return card;
}