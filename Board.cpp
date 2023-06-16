/*
* Filename: Board.cpp
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: This source file contains the implementation of a Class that represents a checkers board
*/
#include <iostream>
#include<windows.h>
#include "Board.h"
#include "Piece.h"

#define BLACK 0
#define WHITE 7
#define LIGHTBLUE 9 
#define LIGHTRED 12
#define GRAY 8

using std::cout;
using std::endl;

HANDLE  hConsole; //represents resource managed by windows kernel. used to access/modify console output.




//constructor
Board::Board() {
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	populatePieces();
}

void Board::setTextAndBackgroundColor(int textColor, int textBackgroundColor) {
	//int textColor = 7;
	//int textBackgroundColor = 0;
	int ColorAttribute = textColor + (textBackgroundColor * 16);
	SetConsoleTextAttribute(hConsole, ColorAttribute);
}

void Board::printSquare(int rowIndex, int colIndex) {
	

	if ((rowIndex + colIndex) % 2) {
		
		if (checkPositionForPiece(rowIndex, colIndex)) {
			//set color
			setTextAndBackgroundColor(pieces[rowIndex][colIndex].getColor(), BLACK);
			//check if type is man or king 
			cout << "O ";
		}
		else {
			setTextAndBackgroundColor(WHITE, BLACK);
			cout << "  ";
		}

		//pieces[rowIndex][colIndex].getColor()
	}
	else {
		setTextAndBackgroundColor(BLACK, WHITE);
		cout << ("  ");
	}

}


void Board::printRow(int rowIndex) {
	for (int columnIndex = 0; columnIndex < 8; columnIndex++) {
		printSquare(rowIndex, columnIndex);

	}

	cout << endl;
}

void Board::printBoard() {
	for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
		setTextAndBackgroundColor(WHITE, BLACK);
		cout << rowIndex << " ";
		printRow(rowIndex);
	}
	cout << endl;
	setTextAndBackgroundColor(WHITE, BLACK);
}

void Board::populatePieces() {

	//instantiate / set piece positions
	for (int rowIndex = 0; rowIndex < 8; rowIndex++) {

		for (int columnIndex = 0; columnIndex < 8; columnIndex++) {

			if (rowIndex != 3 && rowIndex != 4) { //don't populate center rows with pieces
			
				if ((rowIndex + columnIndex) % 2) {
					if (rowIndex < 3)
						this->pieces[rowIndex][columnIndex] = Piece(LIGHTRED);
					else
						this->pieces[rowIndex][columnIndex] = Piece(GRAY);
				}
					
			}
		}
	}

}

bool Board::checkPositionForPiece(int rowPosition, int colPosition) {
	if (this->pieces[rowPosition][colPosition].getColor() != -1) {
		return true;
	}
	return false;

}
Piece Board::getPieceInfo(int rowPosition, int colPosition) {
	return this->pieces[rowPosition][colPosition];
}
/*
int Board::checkPositionForPiece(vector<int>position) {
	for (int i = 0; i < 24; i++) {
		if (pieces[i].getPosition() == position) {
			return i;
		}
	}
	return -1;
	
}
*/