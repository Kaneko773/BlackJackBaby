#include <iostream>

#include "Player.h"
#include "Shoe.h"

using namespace std;

Player::Player(const char* name) : Person(name)
{

}

Player::~Player()
{

}
// �^�[������ false:�o�[�X�g�Atrue:�X�^���h
bool Player::play(Shoe* pShoe)
{
	//�o�[�X�g����܂Ń��[�v����
	while (continueGame("hit")) {
		cout << "hit or stand >> ";

		//����
		char str[16]; //������^
		cin >> str; //����������
		//hit�����͂��ꂽ�ꍇ
		if (strcmp(str, "hit") == 0) {
			//�J�[�h�̔z�z
			hit(pShoe);

			//��D�̕\��
			cout << "====================" << endl;
			cout << "player" << endl;
			showHand();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			//�Ԃ�l��true�Ƃ��ďI��
			return continueGame("stand");
		}
	}
	//�o�[�X�g���Ă���̂�false��Ԃ��ďI��
	return continueGame("");
}