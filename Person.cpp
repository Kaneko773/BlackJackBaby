#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

#include "Person.h"
#include "Shoe.h"

using namespace std;

Person::Person(const char* pName) {
	//fill_n(_hand, 16, -1);	// 配列を-1で埋める
	Card nonCard;//マーク、数字共に -1 が入ってるカード
	for (int i = 0; i < 16; ++i) {
		_hand[i] = nonCard;
	}
	_cardNum = 0;

	_pName = new char[strlen(pName) + 1];
	strcpy(_pName, pName);
}

Person::~Person()
{
	if (_pName != nullptr)
	{
		delete _pName;
		_pName = nullptr;
	}
}

const char* Person::getName() const
{
	return _pName;
}

const int Person::get_cardNum() const
{
	return _cardNum;
}

void Person::hit(Shoe* pShoe)
{
	Card nonCard;
	Card card;
	card = pShoe->takeCard();
	if (!(card == nonCard)) {
		if (_cardNum <= 15) {
			_hand[_cardNum] = card;
			_cardNum++;
		}
		else
		{
			cout << "手札がいっぱいです" << endl;
		}
	}
	else
	{
		cout << "カードが引けませんでした。" << endl;
	}
}

void Person::showHand()
{
	//標準出力
	cout << "hand: ";
	//配列の最初から最後までを順に表示
	for (int i = 0; i < _cardNum; i++) {
		_hand[i].Show();
	}
	//改行
	cout << endl;
	cout << "score: " << calcScore() << endl; //スコアの表示
}

void Person::showOneCard(int num)
{
	_hand[num].Show();
}

int Person::calcScore()
{
	int* data = NULL; //スコア計算用配列用ポインタ

	if (_cardNum <= 0) return 0;

	data = new(nothrow) int[_cardNum]; //手札枚数確保
	if (data == NULL)
	{
		// メモリ不足は今回はバーストとして終了する。
		cout << "メモリの確保に失敗しました。再起動してください。" << endl;
		return 0;
	}
	//手札配列からデータを取得,1-10の値として格納
	for (int i = 0; i < _cardNum; i++) {
		if (_hand[i].get_number() < 10) {
			//配列の値が10以下(0-9)であれば1を加えて格納
			*(data + i) = _hand[i].get_number() + 1;
		}
		else {
			//ここで10を格納しているのは,11-13のカードのこと
			*(data + i) = 10;
		}
	}

	//ソート（Aをあぶりだすため）
	sort(data, data + _cardNum);

	//返り値用変数(計算結果)
	int score = 0;
	//2番目から順にスコアを足していく
	//1番目が0の場合(つまりAである。2枚続く可能性はあるが2枚目のAは必ず1としてカウントする
	//ので先頭だけ調べればよい
	for (int i = 1; i < _cardNum; i++) {
		//スコアにデータを加える
		score = score + (*(data + i));
	}

	//先頭が1(A)であるか判定し状況によって1 or 11として計算
	if (*data == 1) {
		if (score + 11 < 22) { //11として扱ってもバーストしない場合
			//11を加える
			score += 11;
		}
		else {
			//11として扱うとバーストする場合
			//スコアに1を加える
			score += 1;
		}
	}
	else {
		//先頭が1でないなら,スコアにデータをそのまま加える
		score += data[0];
	}

	//バーストである場合は0を返す
	if (score > 21) {
		score = 0;
	}

	// 解放
	if (data != NULL)
	{
		delete[] data;
		data = NULL;
	}

	return score;
}

bool Person::play(Shoe* pShoe) {

	return playBase(pShoe);

}
