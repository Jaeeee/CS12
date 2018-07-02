#ifndef WIZ_H
#define WIZ_H

#include <iostream>
#include "Character.h"

using namespace std;

class Wizard:public Character {
	public:
		Wizard(const string &, double, double, int);
		void attack(Character &);

	private:
		int rank;
};



#endif