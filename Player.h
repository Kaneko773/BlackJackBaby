#pragma once

#include "Person.h"

class Shoe;

class Player : public Person
{
public:
	Player(const char* name);
	virtual ~Player();

public:
	bool playBase(Shoe* pShoe);	// ƒ^[ƒ“ˆ—
};