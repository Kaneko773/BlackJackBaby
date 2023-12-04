#pragma once

class Shoe;

class Person
{
private:
	int _hand[16];	// 手札情報;
	int _cardNum;	// 手札の枚数

	char* _pName;	// 名前

public:
	Person(const char* pName);
	virtual ~Person();

	void hit(Shoe* shoe);	// シューから１枚ひく

	void showHand();	// 手札を表示

	int calcScore();	// スコアを計算して返す

	const char* getName() const;

	bool continueGame(const char* selection);
};
