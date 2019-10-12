#pragma once
#include <iostream>

class Character
{
public:
	Character();
	~Character();

	enum WeaponChoice { NONE_W, LANCE, SWORD, AXE, HAMMER, FISTS, DAGGER, FLAIL };
	int m_weaponDamages[8]{ 0,3,3,4,5,2,3,4 };
	enum SpellChoice { NONE_S, DBREATH, IGNITE, FBITE, IBEAM, SBOLT };
	int m_spellDamages[6]{ 0,8,4,6,4,3 };
	enum ShieldChoice { NONE_SH, FIRE, ICE, ELEC };

	

protected:

	static int m_weaponDamage;
	static int m_spellDamage;

	bool m_burning = false;
	bool m_frozen = false;
	bool m_paralysed = false;

	std::string m_name;

	WeaponChoice m_chosenWep{ FISTS };
	SpellChoice m_chosenSpell{ IBEAM };
	ShieldChoice m_chosenShield{ ICE };

public:

	virtual int calcDamage(WeaponChoice t_enemyWep, SpellChoice t_enemySpell, 
								   bool t_usingWeapon, bool t_usingSpell) = 0;

	virtual bool isUsingWep() const = 0;
	virtual bool isUsingSpell() const = 0;
	virtual void pickAction() = 0;

	std::string getName() const { return m_name; };
	WeaponChoice getWeapon() const { return m_chosenWep; };
	SpellChoice getSpell() const { return m_chosenSpell; };
	ShieldChoice getShield() const { return m_chosenShield; };
};

