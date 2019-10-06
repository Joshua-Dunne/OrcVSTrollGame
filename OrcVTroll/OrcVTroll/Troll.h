#pragma once
#include "Character.h"
#include <stdlib.h> // allows use of rand() function, as Troll is AI controlled.

class Troll : public Character
{
public:
	Troll();
	Troll(WeaponChoice t_startingWep, SpellChoice t_startingSpell, ShieldChoice t_startingShield);

	/*static WeaponChoice m_chosenWep;
	static SpellChoice m_chosenSpell;
	static ShieldChoice m_chosenShield;*/

	~Troll();

private:

	int  m_takenDamage = 0; // how much damage they've taken
	bool  m_shieldUsed = false; // if the shield has been used before, don't use it again
	bool  m_shieldActive = false; // if the shield is currently active

	

public:
	void chooseWeapon();
	void chooseSpell();
	void chooseShield();
	void useShield();
	virtual int calcDamage(WeaponChoice t_enemyWep, SpellChoice t_enemySpell);
	
};

