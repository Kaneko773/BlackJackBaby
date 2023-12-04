#pragma once

#include "common.h"

class Shoe
{
private:
	int _cardShoe[CARD_NUM];
	int _cardNum;

	void _shuffle();
public:
	Shoe();
	virtual ~Shoe();

public:
	int takeCard();	//　カードを１枚返す
};