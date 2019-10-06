#include "Troll.h"

Troll::Troll()
{
}

Troll::Troll(WeaponChoice t_startingWep, SpellChoice t_startingSpell, ShieldChoice t_startingShield)
{
	m_chosenWep = t_startingWep;
	m_chosenSpell = t_startingSpell;
	m_chosenShield = t_startingShield;
}

Troll::~Troll() // unused
{
}

void Troll::chooseWeapon()
{

}

void Troll::chooseSpell()
{

}

void Troll::chooseShield()
{

}

/// <summary>
/// Randomly decide if the shield will be used this action.
/// </summary>
void Troll::useShield()
{
	if (!m_shieldUsed) // make sure the shield hasn't already been used
	{
		int chance = 0;

		chance = rand() % 10 + 1;

		if (chance > 5) // 50% chance of deciding to activate shield
		{
			m_shieldActive = true;
			m_shieldUsed = true;
		}
	}
}

/// <summary>
/// Calculate damage the Troll will take
/// </summary>
/// <param name="t_enemyWep">Enemy's weapon type</param>
/// <param name="t_enemySpell">Enemy's chosen spell</param>
/// <returns>Total damage taken</returns>
int Troll::calcDamage(WeaponChoice t_enemyWep, SpellChoice t_enemySpell)
{
	int finalDamage = 0; // total damage taken 
	int chance = 0; // decide if effects go through

	switch (t_enemyWep)
	{
	case WeaponChoice::LANCE:
		finalDamage += 3;
		std::cout << "Hit with Lance! Troll takes 3 damage." << std::endl;
		break;
	case WeaponChoice::SWORD:
		finalDamage += 3;
		std::cout << "Hit with Sword! Troll takes 3 damage." << std::endl;
		break;
	case WeaponChoice::AXE:
		finalDamage += 3;
		std::cout << "Hit with Axe! Troll takes 3 damage." << std::endl;
		break;
	case WeaponChoice::HAMMER:
		finalDamage += 3;
		std::cout << "Hit with Hammer! Troll takes 3 damage." << std::endl;
		break;
	case WeaponChoice::FISTS:
		finalDamage += 2;
		std::cout << "Hit with Fists! Troll takes 2 damage." << std::endl;
		break;
	case WeaponChoice::DAGGER:
		finalDamage += 3;
		std::cout << "Hit with Dagger! Troll takes 3 damage." << std::endl;
		break;
	case WeaponChoice::FLAIL:
		finalDamage += 4;
		std::cout << "Hit with Flail! Troll takes 4 damage." << std::endl;
		break;
	default:
		std::cout << "error with weapon choice" << std::endl;
		break;
	}

	switch (t_enemySpell)
	{
	case SpellChoice::DBREATH:
		if (!m_shieldActive || m_chosenShield != ShieldChoice::FIRE) // if they don't have their shield up
		{														 // or if the shield they chose wasn't fire
			finalDamage += 6;
			std::cout << "Hit with Dragon Breath! Troll took 6 damage." << std::endl;
		}
		else // otherwise if it's active and it's the right shield
		{
			std::cout << "Dragon Breath was blocked by Fire Shield!" << std::endl;
		}
		break;
	case SpellChoice::IGNITE:

		if (!m_shieldActive || m_chosenShield != ShieldChoice::FIRE)  // if they don't have their shield up
		{														  // or if the shield they chose wasn't fire
			finalDamage += 3;
			std::cout << "Hit with Ignite! Troll took 3 damage." << std::endl;

			chance = rand() % 10 + 1;

			if (chance > 8) // 20% chance to burn
			{
				m_burning = true;
			}
		}
		else // otherwise if it's active and it's the right shield
		{
			std::cout << "Ignite was blocked by Fire Shield!" << std::endl;
		}
		break;
	case SpellChoice::FBITE:

		if (!m_shieldActive || m_chosenShield != ShieldChoice::ICE)  // if they don't have their shield up
		{
				finalDamage += 4;
				std::cout << "Hit with Frost Bite! Troll took 4 damage." << std::endl;		
		}
		else
		{
			std::cout << "Frost Bite was blocked by Ice Shield!" << std::endl;
		}

		break;
	case SpellChoice::IBEAM:

		if (!m_shieldActive || m_chosenShield != ShieldChoice::ICE)  // if they don't have their shield up
		{														  // or if the shield they chose wasn't fire
			finalDamage += 6;
			std::cout << "Hit with Ice Beam! Troll took 4 damage." << std::endl;

			chance = rand() % 10 + 1;

			if (chance > 7) // 30% chance to burn
			{
				m_frozen = true;
				std::cout << "Troll was frozen solid! He'll go second in the next round!" << std::endl;
			}
		}
		else
		{
			std::cout << "Ice Beam was blocked by Ice Shield!" << std::endl;
		}
		break;
	case SpellChoice::SBOLT:

		if (!m_shieldActive || m_chosenShield != ShieldChoice::ELEC)  // if they don't have their shield up
		{														  // or if the shield they chose wasn't fire
			finalDamage += 3;
			std::cout << "Hit with Sky Bolt! Troll took 3 damage." << std::endl;

			chance = rand() % 10 + 1;

			if (chance > 9) // 10% chance to burn
			{
				m_paralysed = true;
				std::cout << "Troll was paralysed! Troll misses his next action!" << std::endl;
			}
		}
		else
		{
			std::cout << "Skybolt was blocked by Electric Shield!" << std::endl;
		}
		break;
	default:
		std::cout << "Error with shield choice -- may have unassigned or assigned shield wrongly!" << std::endl;
		break;
	}


	if (m_burning)
	{
		finalDamage += 2;
		std::cout << "On fire! Troll took 2 damage." << std::endl;
	}

	return finalDamage;
}
