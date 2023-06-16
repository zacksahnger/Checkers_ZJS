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

void Board::printWhiteSquare() {
	//Piece foundPiece = checkPositionForPiece();
	setTextAndBackgroundColor(BLACK, WHITE);
	cout << ("  ");
}

void Board::printBlackSquare() {
	setTextAndBackgroundColor(WHITE, BLACK);
	cout << ("  ");
}

void Board::printRowBlackFirst() {
	for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
		if (rowIndex % 2) {
			printBlackSquare();
		}
		else {
			printWhiteSquare();
		}
	}
	cout << endl;
}
void Board::printRowWhiteFirst() {
	for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
		if (!(rowIndex % 2)) {
			printBlackSquare();
		}
		else {
			printWhiteSquare();
		}
	}
	cout << endl;
}


void Board::printRow(int rowIndex) {
	bool rowIsOdd = rowIndex % 2;
	for (int columnIndex = 0; columnIndex < 8; columnIndex++) {
		bool columnIsOdd = columnIndex % 2;

		//if (checkPositionForPiece({ rowIndex,columnIndex }) == -1) {
			//if ((rowIsOdd && !columnIsOdd) || (!rowIsOdd && columnIsOdd)) {
			  if((rowIndex+columnIndex) % 2){
				printBlackSquare();
			}
			else {
				printWhiteSquare();
			}
		//}

	}

	cout << endl;
}

void Board::printBoard() {
	for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
		setTextAndBackgroundColor(WHITE, BLACK);
		cout << rowIndex << " ";
		printRow(rowIndex);
		/*
		if ((columnIndex % 2)) {
			printRowWhiteFirst();
		}
		else {
			printRowBlackFirst();
		}
		*/
	}
	cout << endl;
	setTextAndBackgroundColor(WHITE, BLACK);
}

void Board::populatePieces() {

	//instantiate / set piece positions
	for (int rowIndex = 0; rowIndex < 8; rowIndex++) {
		bool rowIsOdd = rowIndex % 2;

		for (int columnIndex = 0; columnIndex < 8; columnIndex++) {
			bool columnIsOdd = columnIndex % 2;

			if (rowIndex != 3 && rowIndex != 4) { //don't populate center rows with pieces

				if ((rowIsOdd && !columnIsOdd) || (!rowIsOdd && columnIsOdd)) {
					if(rowIndex < 3)
						this->pieces.push_back(Piece(LIGHTRED, { rowIndex,columnIndex }));
					else
						this->pieces.push_back(Piece(GRAY, { rowIndex,columnIndex }));
				}
					
			}
		}
	}

}

int Board::checkPositionForPiece(vector<int>position) {
	for (int i = 0; i < 24; i++) {
		if (pieces[i].getPosition() == position) {
			return i;
		}
	}
	return -1;
	
}