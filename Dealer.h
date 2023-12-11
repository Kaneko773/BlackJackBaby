#pragma once

#include "Person.h"
class Shoe;

class Dealer : public Person
{
public:
	Dealer();
	Dealer(const char* name);
	virtual ~Dealer();

public:
	bool playBase(Shoe* pShoe);	// ƒ^[ƒ“ˆ—
};
