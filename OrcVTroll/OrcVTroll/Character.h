#pragma once

class Character
{
public:
	Character();
	~Character();

protected:
	enum WeaponChoice { NONE_W, LANCE, SWORD, AXE, HAMMER, FISTS, DAGGER, FLAIL };
	enum SpellChoice { NONE_S, DBREATH, IGNITE, BURN, FBITE, IBEAM, FREEZE, SBOLT };
	enum ShieldChoice { NONE_SH, FIRE, ICE, ELEC };
	WeaponChoice chosenWep{ NONE_W };
	SpellChoice chosenSpell{ NONE_S };
	ShieldChoice chosenShield{ NONE_SH };

	int weaponDamage = 0;
	int spellDamage = 0;

	bool burning = false;
	bool frozen = false;
	bool paralysed = false;

public:
	virtual int calcDamage(WeaponChoice t_enemyWep, SpellChoice t_enemySpell) = 0;
};

