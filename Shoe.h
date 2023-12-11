#pragma once

#include "common.h"
#include "Card.h"

class Shoe
{
private:
	Card _cardShoe[CARD_NUM];
	int _cardNum;

	void _shuffle();
public:
	Shoe();
	virtual ~Shoe();

public:
	Card takeCard();	//　カードを１枚返す
};