/// <summary>
/// Joshua Dunne
/// C00241588
/// </summary>

#pragma once
#include "Character.h"
#include <stdlib.h> // allows use of rand() function, as Troll is AI controlled.

class Troll : public Character
{
public:
	Troll();
	Troll(Character::WeaponChoice t_startingWep, Character::SpellChoice t_startingSpell, 
												Character::ShieldChoice t_startingShield);
	~Troll();

private:
	int m_takenDamage = 0; // how much damage they've taken
	int m_spellsLeft = 2; // how many spells that can be used
	int m_shieldDuration = 2; // how many turns the shield can last for
	int m_turnPriority = 0; // if the Troll goes first or second (0 is last, 1 is neutral, 2 is first)

	bool m_usingWeapon = false; // used to say if the AI is attacking with a weapon
	bool m_usingSpell = false; // used to say if the AI is attacking with a spell

	bool  m_shieldUsed = false; // if the shield has been used before, don't use it again
	bool  m_shieldActive = false; // if the shield is currently active

public:
	void chooseWeapon();
	void chooseSpell();
	void chooseShield();
	void decreaseShieldDuration();
	bool useShield();
	int getPriority() const;
	virtual void pickAction();
	virtual bool isUsingWep() const;
	virtual bool isUsingSpell() const;
	virtual int calcDamage(Character::WeaponChoice t_enemyWep, Character::SpellChoice t_enemySpell,
															bool t_usingWeapon, bool t_usingSpell);
	
};

