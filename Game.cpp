/*
* Filename: Game.cpp
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: This file contains the implementation of a Class that represents a checkers game.
* This class manages user input, scoring, turns, and legal moves.
* to start a game, run game.startGame()
*/

#include "Game.h"
#include<string>
#include<cmath>
using std::cout;
using std::cin;
using std::endl;
using std::string;

Game::Game() {
	this->ElapsedTurns = 0;
	this->isBlueTurn = true;
	this->isGameOver = false;
	
}

void Game::startGame() {

	mainGameLoop();
}

void Game::mainGameLoop() {
	while (!isGameOver && ElapsedTurns < 10) {
		string userInput = "";
		int rowCurrent = -1;
		int colCurrent = -1;
		int rowTarget = -1;
		int colTarget = -1;

		this->gameBoard.printBoard();

		if (ElapsedTurns % 2) {
			isBlueTurn = false;
			cout << "It's Reds turn!" << endl;
		}
		else {
			isBlueTurn = true;
			cout << "It's Blues turn!" << endl;
		}

		//user input
		cout << "Please input the coordinates of the piece you'd like to move (row,col)" << endl;
		cin >> userInput;

		//if (userInput.size() > 2) { //need at least 3 input characters for correct format.
			rowCurrent = charToInt(userInput[0]);
			colCurrent = charToInt(userInput[2]);
		//}
		cout << rowCurrent << "," << colCurrent << endl;

		/*if (!validateUserInput(userInput)) {
			cout << "invalid input! please try again!" << endl;
			ElapsedTurns--;
			}*/
		cout << "Please input the coordinates of the space you'd like to move to (row,col)" << endl;

		cin >> userInput;
		//if (userInput.size() > 2) { //need at least 3 input characters for correct format.
			rowTarget = charToInt(userInput[0]);
			colTarget = charToInt(userInput[2]);
		//}
		cout << rowTarget << "," << colTarget << endl;

		//pull this all into a method "checkMoveValidity"
		Piece selectedPiece = this->gameBoard.pieces[rowCurrent][colCurrent];
		Piece targetPiece = this->gameBoard.pieces[rowTarget][colTarget];
		
		if (selectedPiece.getType() != SPACE) {
			if ((isBlueTurn && selectedPiece.getColor() == LIGHTBLUE) || (!isBlueTurn && selectedPiece.getColor() == LIGHTRED)) {

				if ((float)(sqrt(pow(colCurrent - rowCurrent, 2) + pow(colTarget - rowTarget, 2))) < 2) {
					cout << "REGULAR MOVE" << endl;
					//regular move
					this->gameBoard.pieces[rowTarget][colTarget] = this->gameBoard.pieces[rowCurrent][colCurrent];
					this->gameBoard.pieces[rowCurrent][colCurrent].setType(SPACE);
				}//regular move
				else {
					cout << "JUMP" << endl;
					//jump (garbage code alert)


					int rowJumpDirection = (rowTarget - rowCurrent) / abs(rowTarget - rowCurrent);
					int jumpedSquareRow = rowCurrent + 1*rowJumpDirection;
					int colJumpDirection = (colTarget - colCurrent) / abs(colTarget - colCurrent);
					int jumpedSquareCol = colCurrent + 1*colJumpDirection;

					//cout << "Jumped piece row,col: " << jumpedSquareCol << "," << jumpedSquareCol << endl; //doesn't work but it does.
					this->gameBoard.pieces[jumpedSquareRow][jumpedSquareCol].setType(SPACE);// remove jumped piece
					this->gameBoard.pieces[rowTarget][colTarget] = this->gameBoard.pieces[rowCurrent][colCurrent];
					this->gameBoard.pieces[rowCurrent][colCurrent].setType(SPACE);

				} //jump

			} //if turn and piece color is valid
		} //if selected piece exists


		//check if anyone is out of pieces.

		//check for stalemates.

		ElapsedTurns++;
	}
}

//for internal use. converts characters to integers to streamline user input
int Game::charToInt(char inputCharacter){
	return inputCharacter - 48;
}

//TODO. validate user input
bool Game::validateUserInput(string input) {
	if ((charToInt(input[0]) > 7 || charToInt(input[0]) < 0) || (charToInt(input[2]) > 7 || charToInt(input[2]) < 0)) {
		return false;
	}
	return true;
}