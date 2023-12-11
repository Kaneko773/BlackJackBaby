#include <iostream>
#include "Shoe.h"

using namespace std;

// コンストラクタ
Shoe::Shoe()
{
	_cardNum = CARD_NUM;	//カード枚数初期化
	// カード初期化
	int i = 0;
	for (int j = 0; j < MARK_NUM; ++j)
	{
		for (int k = 0; k < NUMBER_NUM; ++k) {
			_cardShoe[i].set_mark(j);
			_cardShoe[i].set_number(k);
			++i;
		}
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
Card Shoe::takeCard()
{
	Card noncard;//マーク、数字共に -1 が入ってるカード
	// 後ろから引いてく方がロジック的に楽ちんかと。
	if (_cardNum <= 0) return noncard;
	_cardNum--;
	Card card = _cardShoe[_cardNum];
	_cardShoe[_cardNum] = noncard;	// 念のためいれとく（デバッグ用）

	return card;
}