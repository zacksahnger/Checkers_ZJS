#pragma once
/*
* Filename: Game.h
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: This file contains the declaration of a Class that represents a checkers game.
* This class manages user input, scoring, turns, and legal moves.
* to start a game, run game.startGame()
*/
#include "Board.h"
#include <string>
class Game
{
public:
	Board gameBoard;
	Game();
	void startGame();
	
private:
	int ElapsedTurns;
	bool isBlueTurn;
	bool isGameOver;
	void mainGameLoop();
	int charToInt(char inputCharacter);
	bool validateUserInput(std::string input);
	
};

