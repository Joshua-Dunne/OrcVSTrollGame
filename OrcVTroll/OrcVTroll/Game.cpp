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
		m_currentState = GameState::GAMEPLAY;
		std::cout << "*********************************************" << std::endl;
		std::cout << "You are the greatest Orc fighter in your City.\n";
		std::cout << "No Troll or Orc has or ever will defeat you in battle.\n";
		std::cout << "Soon, you will stand at the middle of both Cities, coming to face the Troll's greatest fighter.\n";
		std::cout << "If you beat the greatest Troll fighter, you can easily claim their City. However..\n";
		std::cout << "If you lose yourself, your city will be run by the Trolls.\n";
		std::cout << "Good luck.\n";
		std::cout << "*********************************************" << std::endl << std::endl;

		m_orc.chooseWeapon();
		m_orc.chooseSpell();
		m_orc.chooseShield();

		m_troll.chooseWeapon();
		m_troll.chooseSpell();
		m_troll.chooseShield();
		std::cout << std::endl << "*********************************************" << std::endl;
		std::cout << "Both you and the greatest fighter of the Trolls both finally meet, and raise your weapons." << std::endl;

		while (m_currentState == GameState::GAMEPLAY)
		{
			if (m_currentTurn == TurnState::ORC) // if it's the Orc's turn
			{
				m_currentPlayer = &m_orc; //set up name and damage for the Troll
				m_currentDamage = &m_trollDamage;
				m_charTakingDamage = &m_troll;
				// since the Orc will be attacking the Troll

				m_turnCount++; // Increase the turn count (2 turns per round)

				if (m_turnCount >= m_MAX_TURNS)
				{
					m_currentTurn = TurnState::WAITING; // if both players have taken their turns,
														// give the player a chance to look over the results
				}
				else
				{ 
					m_currentTurn = TurnState::TROLL; // otherwise it is the other player's turn
				}
			}
			else if (m_currentTurn == TurnState::TROLL)
			{
				m_currentPlayer = &m_troll;
				m_currentDamage = &m_orcDamage;
				m_charTakingDamage = &m_orc;

				m_turnCount++;

				if (m_turnCount >= m_MAX_TURNS)
				{
					m_currentTurn = TurnState::WAITING; // if both players have taken their turns,
														// give the player a chance to look over the results
				}
				else
				{
					m_currentTurn = TurnState::ORC; // otherwise it is the other player's turn
				}
			}
			else
			{
				std::cout << "Both turns taken." << std::endl;
				system("Pause");
				m_turnCount = 0;
				m_roundCount++;

				if (m_roundCount < m_MAX_ROUNDS)
				{	
					std::cout << "Deciding next turn: ";
					int chance = 0;
					chance = rand() % 10 + 1;

					if (chance > 5)
					{
						m_currentTurn = TurnState::ORC;
						std::cout << "Orc goes first" << std::endl;
					}
					else
					{
						m_currentTurn = TurnState::TROLL;
						std::cout << "Troll goes first" << std::endl;
					}
				}
				else
				{
					std::cout << "Round over." << std::endl;
					std::cout << "Troll took: " << m_trollDamage << std::endl;
					std::cout << "Orc took: " << m_orcDamage << std::endl << std::endl;
					if (m_trollDamage > m_orcDamage)
					{
						std::cout << "Troll took more damage. Orc wins!" << std::endl;
					} else if (m_orcDamage > m_trollDamage)
					{
						std::cout << "Orc took more damage. Troll wins!" << std::endl;
					}
					else
					{
						std::cout << "Both Players took the same damage. It's a Tie!" << std::endl;
					}
					m_currentState = GameState::QUIT; // we're done, so we break out of the loop
				}
			}

			if (m_turnCount != 0)
			{ // turn count always gets increased by 1 when a turn is decided,
			  // so i use this check to make sure damage calculation isnt done when it isn't someone's turn
				m_currentName = m_currentPlayer->getName();
				m_currentPlayer->pickAction();
				*m_currentDamage += m_charTakingDamage->calcDamage(m_currentPlayer->getWeapon(),
					m_currentPlayer->getSpell(),
					m_currentPlayer->isUsingWep(),
					m_currentPlayer->isUsingSpell());

				std::cout << m_charTakingDamage->getName() << " has taken " << *m_currentDamage
					<< " damage total from the " << m_currentName << std::endl << std::endl;
			}
			//std::cout << "Relooping..." << std::endl;
		}
	}
}