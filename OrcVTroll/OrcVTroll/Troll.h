#pragma once
#include "Character.h"
#include <stdlib.h> // allows use of rand() function, as Troll is AI controlled.

class Troll : public Character
{
public:
	Troll();
	~Troll();

private:

	int takenDamage = 0; // how much damage they've taken
	bool shieldUsed = false; // if the shield has been used before, don't use it again
	bool shieldActive = false; // if the shield is currently active

public:
	void chooseWeapon();
	void chooseSpell();
	void chooseShield();
	void useShield();
	virtual int calcDamage(WeaponChoice t_enemyWep, SpellChoice t_enemySpell);
	
};

