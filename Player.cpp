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
// ターン処理 false:バースト、true:スタンド
bool Player::playBase(Shoe* pShoe)
{
	//バーストするまでループ処理
	while (calcScore() > 0) {
		cout << "hit or stand >> ";

		//入力
		char str[16]; //文字列型
		cin >> str; //文字列を入力
		//hitが入力された場合
		if (strcmp(str, "hit") == 0) {
			//カードの配布
			hit(pShoe);

			//手札の表示
			cout << "====================" << endl;
			cout << getName() << endl;
			showHand();
			cout << "====================" << endl;
		}
		else if (strcmp(str, "stand") == 0) {
			//返り値をtrueとして終了
			return true;
		}
	}
	//バーストしているのでfalseを返して終了
	return false;
}