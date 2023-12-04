#include <iostream>
#include "Shoe.h"

using namespace std;

// コンストラクタ
Shoe::Shoe()
{
	_cardNum = CARD_NUM;	//カード枚数初期化
	// カード初期化
	for (int i = 0; i < CARD_NUM; i++)
	{
		_cardShoe[i] = i;
	}

	_shuffle();	// シャッフルする
}

Shoe::~Shoe()
{

}

//シャッフル（フィッシャーイェーツ）
void Shoe::_shuffle()
{
	for (int i = _cardNum; i > 1; --i) {
		int a = i - 1;
		int b = rand() % i;
		swap(_cardShoe[a], _cardShoe[b]);
	}
}

// カードがない場合は-1を返します。
int Shoe::takeCard()
{
	// 後ろから引いてく方がロジック的に楽ちんかと。
	if (_cardNum <= 0) return -1;
	_cardNum--;
	int card = _cardShoe[_cardNum];
	_cardShoe[_cardNum] = -1;	// 念のためいれとく（デバッグ用）

	return card;
}