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

	spaces.reserve(8);
	populateSpaces();
	populatePieces();
}

void Board::setTextAndBackgroundColor(int textColor, int textBackgroundColor) {
	int ColorAttribute = textColor + (textBackgroundColor * 16);
	SetConsoleTextAttribute(hConsole, ColorAttribute);
}

void Board::printSquare(int rowIndex, int colIndex) {
	

	if ((rowIndex + colIndex) % 2) { //black background
		
		if (checkPositionForPiece(rowIndex, colIndex)) {
			//set color
			setTextAndBackgroundColor(spaces[rowIndex][colIndex]->getColor(), BLACK);
			//check if type is man or king 
			cout << spaces[rowIndex][colIndex]->pieceRepresentation() << " ";
		}
		else {
			setTextAndBackgroundColor(WHITE, BLACK);
			cout << "  ";
		}

		//pieces[rowIndex][colIndex].getColor()
	}
	else { //white background
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
	
	setTextAndBackgroundColor(WHITE, BLACK);
	cout << "  A B C D E F G H";
	cout << endl;
}

void Board::populateSpaces() {
	vector<Space*> tmp;
	for (int i = 0; i < 8; i++) {
		Space* s = new Space();
		tmp.push_back(s);
	}
	for (int i = 0; i < 8; i++) {
		
		spaces.push_back(tmp);
	}
}

void Board::populatePieces() {

	//instantiate / set piece positions
	for (int rowIndex = 0; rowIndex < 8; rowIndex++) {

		for (int columnIndex = 0; columnIndex < 8; columnIndex++) {

			if (rowIndex != 3 && rowIndex != 4) { //don't populate center rows with pieces
			
				if ((rowIndex + columnIndex) % 2) {
					if (rowIndex < 3) {
						Piece* p = new Piece(LIGHTRED);
						this->spaces[rowIndex][columnIndex] = p;//Piece(LIGHTRED);
					}

					else {
						Piece* p = new Piece(GRAY);
						this->spaces[rowIndex][columnIndex] = p;
					}

				}
				else {
					//this->spaces[rowIndex][columnIndex] = Space();
				}
					
			}
		}
	}

}

bool Board::checkPositionForPiece(int rowPosition, int colPosition) {
	if (this->spaces[rowPosition][colPosition]->getColor() != -1) {
		return true;
	}
	return false;

}
Space* Board::getSpaceInfo(int rowPosition, int colPosition) {
	return this->spaces[rowPosition][colPosition];
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