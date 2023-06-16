/*
* Filename: Piece.cpp
* Author: Zachary Sahnger
* Date: 6/14/2023
* Description: Piece is a class that defines the base attributes/behaviors of a checkers base game piece.
*/

#include"Piece.h"

Piece::Piece() {
	this->color = -1;
}
Piece::Piece(int color) { //overload for cases with color provided
	this->color = color;
}

bool Piece::canMoveBackwards() {
	return false;
}
bool Piece::canMoveForwards() {
	return true;
}

char Piece::pieceRepresentation() {
	return 'O';
}


int Piece::getColor() {
	return this->color;
}

void Piece::setColor(int color) {
	this->color = color;
}