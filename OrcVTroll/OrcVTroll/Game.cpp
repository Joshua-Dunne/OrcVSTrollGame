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
	while (currentState != GameState::QUIT)
	{
		update();
		// keep the game running while the player hasn't quit
	}
}


void Game::update()
{
	// loop gameplay
	std::cout << "Enter 0 to quit: ";
	std::cin >> quitGame;

	if (quitGame == 0)
	{
		currentState = GameState::QUIT;
		std::cout << "Quitting..." << std::endl;
	}
	else
	{
		std::cout << "Relooping..." << std::endl;
	}
}