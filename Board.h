#pragma once
/*
* Filename: Board.h
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: This source file contains the declarations for a class that represents a checkers board
*/
#include <iostream>
#include<windows.h>
#include "Piece.h"
/*
class Board {

public:
	Board(); //do I need this?
	void printBoard();

private:

};
*/
class Board {
public:
	Board();
	void printBoard();
	void setTextAndBackgroundColor(int textColor, int textBackgroundColor);
	vector<Piece> pieces;

private:
	void populatePieces();
	void printWhiteSquare();
	void printBlackSquare();
	void printRowBlackFirst();
	void printRowWhiteFirst();
	void printRow(int columnIndex);
	int checkPositionForPiece(vector<int> position);
	
};