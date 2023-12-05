#include <iostream>

#include "Dealer.h"
#include "Shoe.h"

using namespace std;

Dealer::Dealer() : Person("Dealer")
{

}

Dealer::Dealer(const char* name) : Person(name)
{

}

Dealer::~Dealer()
{

}

// �^�[������
bool Dealer::play(Shoe* pShoe)
{
	//�X�R�A��16�ȉ��̏ꍇhit�𑱂���
	while (continueGame("")) {
		//�q�b�g����
		hit(pShoe);
		cout << "hit" << endl;
		//��D�̕\��
		cout << "====================" << endl;
		cout << "dealer" << endl;
		showHand();
		cout << "====================" << endl;
	}
	return continueGame("");
}