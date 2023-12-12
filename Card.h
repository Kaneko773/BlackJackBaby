#pragma once
using namespace std;

class Card
{
public:
	Card();
	virtual ~Card();
	
	//今回は要らない
	void operator=(const Card& other);//代入演算子
	
	bool operator==(const Card& other);//等値演算子

	void set_mark(int mark) {
		//エラーチェックをする
		if (mark < 0 || 3 < mark) {
			cout << "エラーが発生しました" << endl;
			_mark = 0;
		}
		else {
			_mark = mark;
		}
	}
	void set_number(int number) {
		//エラーチェックをする
		if (number < 0 || 12 < number) {
			cout << "エラーが発生しました" << endl;
			_number = 0;
		}
		else {
			_number = number;
		}
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

