#pragma once
#include <iostream>

class Character
{
public:
	Character();
	~Character();

	enum WeaponChoice { NONE_W, LANCE, SWORD, AXE, HAMMER, FISTS, DAGGER, FLAIL };
	enum SpellChoice { NONE_S, DBREATH, IGNITE, FBITE, IBEAM, SBOLT };
	enum ShieldChoice { NONE_SH, FIRE, ICE, ELEC };

protected:
	static WeaponChoice m_chosenWep;
	static SpellChoice m_chosenSpell;
	static ShieldChoice m_chosenShield;

	static int m_weaponDamage;
	static int m_spellDamage;

	bool m_burning = false;
	bool m_frozen = false;
	bool m_paralysed = false;

public:

	virtual int calcDamage(WeaponChoice t_enemyWep, SpellChoice t_enemySpell) = 0;
};

