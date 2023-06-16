/*
* Filename: Source.cpp
* Author: Zachary Sahnger
* Date: 6/14/2023
* Description: This source file contains the implementation of a program that allows two players to play checkers
* in the console
*/

#include <iostream>
//#include <stdlib.h>
#include <windows.h>
#include "Board.h"
#include "Piece.h"
#include "Game.h"
#include<vector>

using std::cout;
using std::endl;


int main() {

	cout << ("Hello world!") << std::endl;


	Game myGame;
	myGame.startGame();

	return 0;
}