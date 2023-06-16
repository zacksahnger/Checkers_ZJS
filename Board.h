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

#include<vector>
using std::vector;
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
	//Space pieces[8][8];
	vector<vector<Space*>> spaces;
	

private:
	void populateSpaces();
	void populatePieces();
	void printSquare(int rowIndex, int colIndex);
	void printRow(int columnIndex);
	bool checkPositionForPiece(int rowPosition, int colPosition);
	Space* getSpaceInfo(int rowPosition, int colPosition);

	
};