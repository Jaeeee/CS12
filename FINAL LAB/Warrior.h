#ifndef WARR_H
#define WARR_H

#include <iostream>
#include "Character.h"

using namespace std;

class Warrior:public Character {
	public:
		Warrior(const string &, double, double, const string &);
		void attack(Character &);

	private:
		string allegiance;
};



#endif