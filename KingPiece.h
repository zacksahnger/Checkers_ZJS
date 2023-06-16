#pragma once
/*
* Filename: KingPiece.h
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: Defines the attributes/behavior of the King piece. Inherits Piece
*/
#include "Piece.h"

class KingPiece : Piece {

	KingPiece();
	KingPiece(int color); //constructor
	int getColor();
	void setColor(int color);
	bool canMoveForwards();
	bool canMoveBackwards();
	char pieceRepresentation();

private:
	int color;
};