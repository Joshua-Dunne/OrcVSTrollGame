/// <summary>
/// Joshua Dunne
/// C00241588
/// </summary>

#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

struct Game
{
public:
	Game() = default;
	~Game();
	/// <summary>
	/// Main method for game
	/// </summary>
	void run(); // starts the game

private:
	void update();

	enum GameState { MENU, GAMEPLAY, QUIT };
	GameState currentState{ MENU };

	int quitGame = 0;
};

#endif // !GAME_HPP