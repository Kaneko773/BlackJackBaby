#include <iostream>
#include "Card.h"

Card::Card() {
	_mark = -1;
	_number = -1;
}
Card::~Card() {

}
/*
void Card::operator=(const Card& other) {
	_mark = other.get_mark();
	_number = other.get_number();
}*/
bool Card::operator==(const Card& other){
	if (_mark == other.get_mark() 
		&& _number == other.get_number())return true;
	return false;
}

void Card::Show() {
	const char* strType[] = { "s", "h", "d", "c" };
	cout << strType[_mark];
	if (_number == 0) {
		cout << "A  ";
	}
	else if (_number < 9) {
		cout << _number + 1 << "  ";
	}
	else if (_number == 9) {
		cout << _number + 1 << " ";
	}
	else {
		switch (_number)
		{
		case 10: cout << "J  "; break;
		case 11: cout << "Q  "; break;
		case 12: cout << "K  "; break;
		}
	}
	
}