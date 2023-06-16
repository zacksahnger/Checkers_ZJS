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
	//vector<Piece> pieces;
	Piece pieces[8][8];
	

private:
	void populatePieces();
	//void printWhiteSquare(int rowIndex, int colIndex);
	//void printBlackSquare( int rowIndex, int colIndex);
	void printSquare(int rowIndex, int colIndex);
	void printRowBlackFirst();
	void printRowWhiteFirst();
	void printRow(int columnIndex);
	bool checkPositionForPiece(int rowPosition, int colPosition);
	Piece getPieceInfo(int rowPosition, int colPosition);

	
};