#pragma once
using namespace std;

class Card
{
public:
	Card();
	virtual ~Card();
	
	//����͗v��Ȃ�
	void operator=(const Card& other);//������Z�q
	
	bool operator==(const Card& other);//���l���Z�q

	void set_mark(int mark) {
		//�G���[�`�F�b�N������
		if (mark < 0 || 3 < mark) {
			cout << "�G���[���������܂���" << endl;
			_mark = 0;
		}
		else {
			_mark = mark;
		}
	}
	void set_number(int number) {
		//�G���[�`�F�b�N������
		if (number < 0 || 12 < number) {
			cout << "�G���[���������܂���" << endl;
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

