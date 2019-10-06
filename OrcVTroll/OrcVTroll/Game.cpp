/// <summary>
/// Joshua Dunne
/// C00241588
/// </summary>

#include "Game.h"

Game::~Game()
{
	// we won't be using the deconstructor but it must be declared
}

void Game::run()
{
	srand(time(NULL)); // set a random seed

	while (m_currentState != GameState::QUIT)
	{
		update();
		// keep the game running while the player hasn't quit
	}

	std::cout << "Thanks for playing." << std::endl;
}


void Game::update()
{
	// loop gameplay
	std::cout << "Enter 0 to quit: ";
	std::cin >> m_quitGame;

	if (m_quitGame == 0)
	{
		m_currentState = GameState::QUIT;
		std::cout << "Quitting..." << std::endl;
	}
	else
	{
		if (m_currentTurn == TurnState::ORC)
		{
			m_currentPlayer = &m_troll;
			m_currentDamage = &m_trollDamage;
			m_currentName = m_currentPlayer->getName();
			*m_currentDamage += m_currentPlayer->calcDamage(Character::WeaponChoice::FISTS, Character::SpellChoice::IGNITE);
			std::cout << m_currentName << " has taken " << *m_currentDamage << " damage total!" << std::endl << std::endl;
		}
		//else
		//{
		//	currentPlayer = &orc;
		//	currentName = currentPlayer->getName();
		//	*currentDamage += currentPlayer->calcDamage(Character::WeaponChoice::FISTS, Character::SpellChoice::IBEAM);
		//	std::cout << currentName << " has taken " << *currentDamage << " damage total!" << std::endl << std::endl;
		//	
		//}
		// will be used later when Orc is put into the game

		std::cout << "Relooping..." << std::endl;
	}
}