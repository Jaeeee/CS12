#include <iostream>
#include "Character.h"
#include "Elf.h"

using namespace std;

Elf::Elf(const string &name, double health, double attackStrength, const string &family)
:Character(ELF, name, health, attackStrength), family(family) {

}

void Elf::attack(Character &enemy) {
	double dmg = 0.0;

	if (!enemy.isAlive()) {
		return;
	}

	if (enemy.getType() == ELF) {
		Elf &opp = dynamic_cast<Elf &>(enemy);

		if (opp.family == family) {
			cout << "Elf " << name << " does not attack Elf " << opp.name << '.' << endl;
			cout << "They are both members of the " << family << " family." << endl;
			return;
		}
	}

	dmg = (health / MAX_HEALTH) * attackStrength;

	enemy.damage(dmg);

	cout << "Elf " << name << " shoots an arrow at " << enemy.getName() << " --- TWANG!!\n";

	if (enemy.isAlive()) {
		cout << enemy.getName() << " takes " << dmg << " damage." << endl;
		return;
	}
		else {
		cout << enemy.getName() << " is dead!" << endl;
		return;
		}
}