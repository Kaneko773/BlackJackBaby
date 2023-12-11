#pragma once
using namespace std;

class Card
{
public:
	Card();
	virtual ~Card();
	void operator=(const Card& other);//‘ã“ü‰‰ŽZŽq
	bool operator==(const Card& other);//“™’l‰‰ŽZŽq

	void set_mark(int mark) {
		_mark = mark;
	}
	void set_number(int number) {
		_number = number;
	}
	int get_mark() const{
		return _mark;
	}
	int get_number() const{
		return _number;
	}

	void Show();

private:
	int _mark;
	int _number;
};

