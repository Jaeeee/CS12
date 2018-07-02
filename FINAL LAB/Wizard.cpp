#include <iostream>
#include "Character.h"
#include "Wizard.h"

using namespace std;

Wizard::Wizard(const string &name, double health, double attackStrength, int rank)
:Character(WIZARD, name, health, attackStrength), rank(rank) {
}

void Wizard::attack(Character &enemy) {

	double dmg = 0.0;

	if (!enemy.isAlive()) {
		return;
	}

	if (enemy.getType() == WIZARD) {
		Wizard &opp = dynamic_cast<Wizard &>(enemy);
		dmg = (static_cast<double>(rank) / opp.rank) * attackStrength;
	}
		else {
			dmg = attackStrength;
		}

	enemy.damage(dmg);

		cout << "Wizard " << name << " attacks " << enemy.getName() << " --- POOF!!\n";

		if (enemy.isAlive()) {
			cout << enemy.getName() << " takes " << dmg << " damage." << endl;
			return;
		}
			else {
			cout << enemy.getName() << " is dead!" << endl;
			return;
			}	
}
