#pragma once
#include "Character.h"
#include <iostream>

class Orc : public Character
{
public:
	Orc();
	Orc(Character::WeaponChoice t_startingWep, Character::SpellChoice t_startingSpell, Character::ShieldChoice t_startingShield);
	~Orc();

private:
	int m_takenDamage = 0; // how much damage they've taken
	int m_spellsLeft = 2; // how many spells that can be used

	bool m_usingWeapon = false; // used to say if the AI is attacking with a weapon
	bool m_usingSpell = false; // used to say if the AI is attacking with a spell

	bool  m_shieldUsed = false; // if the shield has been used before, don't use it again
	bool  m_shieldActive = false; // if the shield is currently active

public:
	void chooseWeapon();
	void chooseSpell();
	void chooseShield();
	bool useShield();
	virtual void pickAction();
	virtual bool isUsingWep() const;
	virtual bool isUsingSpell() const;
	virtual int calcDamage(Character::WeaponChoice t_enemyWep, Character::SpellChoice t_enemySpell,
														    bool t_usingWeapon, bool t_usingSpell);
};

