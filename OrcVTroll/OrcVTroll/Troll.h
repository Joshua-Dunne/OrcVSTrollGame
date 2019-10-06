#pragma once
#include "Character.h"
#include <stdlib.h> // allows use of rand() function, as Troll is AI controlled.

class Troll : public Character
{
public:
	Troll();
	Troll(Character::WeaponChoice t_startingWep, Character::SpellChoice t_startingSpell, Character::ShieldChoice t_startingShield);
	~Troll();

private:
	int  m_takenDamage = 0; // how much damage they've taken

	bool m_usingWeapon = false; // used to say if the AI is attacking with a weapon
	bool m_usingSpell = false; // used to say if the AI is attacking with a spell

	bool  m_shieldUsed = false; // if the shield has been used before, don't use it again
	bool  m_shieldActive = false; // if the shield is currently active

	WeaponChoice m_chosenWep{ FISTS };
	SpellChoice m_chosenSpell{ IBEAM };
	ShieldChoice m_chosenShield{ ICE };

public:
	void chooseWeapon();
	void chooseSpell();
	void chooseShield();
	void useShield();
	void pickAction();
	virtual int calcDamage(Character::WeaponChoice t_enemyWep, Character::SpellChoice t_enemySpell);
	
};

