/*
* Filename: KingPiece.cpp
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: Defines the attributes/behavior of the King piece. Inherits Piece.
*/

#include"KingPiece.h"

KingPiece::KingPiece() {
	this->color = -1;
}
KingPiece::KingPiece(int color) { //overload for cases with color provided
	this->color = color;
}

bool KingPiece::canMoveBackwards() {
	return true;
}
bool KingPiece::canMoveForwards() {
	return true;
}

char KingPiece::pieceRepresentation() {
	return 'X';
}

int KingPiece::getColor() {
	return this->color;
}

void KingPiece::setColor(int color) {
	this->color = color;
}