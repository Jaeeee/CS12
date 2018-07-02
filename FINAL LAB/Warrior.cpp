#include <iostream>
#include "Character.h"
#include "Warrior.h"

using namespace std;

Warrior::Warrior(const string &name, double health, double attackStrength, const string &allegiance)
:Character(WARRIOR, name, health, attackStrength), allegiance(allegiance) {

}

void Warrior::attack(Character &enemy) {
	double dmg = 0.0;

	if (!enemy.isAlive()) {
		return;
	}

	if (enemy.getType() == WARRIOR) {
		Warrior &opp = dynamic_cast<Warrior &>(enemy);

		if (opp.allegiance == allegiance) {
			cout << "Warrior " << name << " does not attack Warrior " << opp.name << '.' << endl;
			cout << "They share an allegiance with " << allegiance << '.' << endl;
			return;
		}
	}

	dmg = (health / MAX_HEALTH) * attackStrength;

	enemy.damage(dmg);

	cout << "Warrior " << name << " attacks " << enemy.getName() << " --- SLASH!!\n";

	if (enemy.isAlive()) {
		cout << enemy.getName() << " takes " << dmg << " damage." << endl;
		return;
	}
		else {
		cout << enemy.getName() << " is dead!" << endl;
		return;
		}


}
