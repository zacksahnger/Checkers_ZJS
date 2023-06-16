/*
* Filename: Board.cpp
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: This source file contains the implementation of a Class that represents a checkers board.
* This board is responsible for printing itself, and keeping track of where pieces are.
*/
#include <iostream>
#include<windows.h>
#include "Board.h"
#include "Piece.h"

using std::cout;
using std::endl;

HANDLE  hConsole; //represents resource managed by windows kernel. used to access/modify console output.

//constructor
Board::Board() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	populatePieces();
}

//set color and background of text on console. used by board::printSquare
void Board::setTextAndBackgroundColor(int textColor, int textBackgroundColor) {
	int ColorAttribute = textColor + (textBackgroundColor * 16);
	SetConsoleTextAttribute(hConsole, ColorAttribute);
}

//Prints squares on the checkerboard. Checks for pieces at each space and prints them if present
void Board::printSquare(int rowIndex, int colIndex) {
	
	if ((rowIndex + colIndex) % 2) { //odd sum of row+column is always a black square
		
		if (checkPositionForPiece(rowIndex, colIndex)) { //if there is a piece in this position
			//set color
			setTextAndBackgroundColor(pieces[rowIndex][colIndex].getColor(), BLACK);
			//check if type is man or king 
			cout << pieces[rowIndex][colIndex].charRepresentation() << ' ';
		}
		else { //no piece found in this position
			setTextAndBackgroundColor(WHITE, BLACK);
			cout << "  ";
		}
	}
	else { //even sum of row+column is always a white square, and never contains a piece
		setTextAndBackgroundColor(BLACK, WHITE);
		cout << ("  ");
	}

}

//print a row of squares. used by Board::printBoard
void Board::printRow(int rowIndex) {
	for (int columnIndex = 0; columnIndex < 8; columnIndex++) {
		printSquare(rowIndex, columnIndex);

	}
	setTextAndBackgroundColor(WHITE, BLACK);
	cout << endl;
}

//print the board to the console
void Board::printBoard() {
	for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
		setTextAndBackgroundColor(WHITE, BLACK);
		cout << rowIndex << " ";
		printRow(rowIndex);

	}
	cout << "  ";
	for (int i = 0; i < 8; i++) {
		cout << i << " ";
	}	
	cout << endl;
}

//fill the board with pieces in their starting positions at the beginning of a game
void Board::populatePieces() {

	//instantiate / set piece positions
	for (int rowIndex = 0; rowIndex < 8; rowIndex++) {

		for (int columnIndex = 0; columnIndex < 8; columnIndex++) {

			if (rowIndex != 3 && rowIndex != 4) { //don't populate center rows with pieces
			
				if ((rowIndex + columnIndex) % 2) {
					if (rowIndex < 3)
						this->pieces[rowIndex][columnIndex] = Piece(MAN,LIGHTRED); //first 3 rows start with red pieces
					else
						this->pieces[rowIndex][columnIndex] = Piece(MAN,LIGHTBLUE); //last 3 rows start with blue pieces
				}
					
			}
		}
	}

}

//checks a given position (row,col) to see if a piece is present
bool Board::checkPositionForPiece(int rowPosition, int colPosition) { //I know this is gross.
	if (this->pieces[rowPosition][colPosition].getColor() != -1) {
		return true;
	}
	return false;

}

//get info about a given piece on the board
Piece Board::getPieceInfo(int rowPosition, int colPosition) {
	return this->pieces[rowPosition][colPosition];
}