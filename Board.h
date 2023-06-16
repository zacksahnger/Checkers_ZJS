#pragma once
/*
* Filename: Board.h
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: This file contains the declaration of a Class that represents a checkers board.
* This board is responsible for printing itself, and keeping track of where pieces are.
*/
#include <iostream>
#include<windows.h>
#include "Piece.h"

class Board {
public:
	Board();
	void printBoard();
	void setTextAndBackgroundColor(int textColor, int textBackgroundColor);
	//vector<Piece> pieces;
	Piece pieces[8][8];
	

private:
	void populatePieces();
	void printSquare(int rowIndex, int colIndex);
	void printRow(int columnIndex);
	bool checkPositionForPiece(int rowPosition, int colPosition);
	Piece getPieceInfo(int rowPosition, int colPosition);

	
};