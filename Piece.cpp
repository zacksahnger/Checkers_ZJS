/*
* Filename: Piece.cpp
* Author: Zachary Sahnger
* Date: 6/14/2023
* Description: This source file contains the implementation of class that represents each piece on the checkerboard
* currently, this class also represents empty spaces, denoted with a 'type' of -1 (check header for piece type definitions)
*/

#include"Piece.h"

Piece::Piece() { //default constructor
	this->color = -1;
	this->type = -1;
}
Piece::Piece(int color) { //overload for cases with color provided
	this->color = color;
	this->type = SPACE;
}

Piece::Piece(int type, int color) { //overload for cases with color provided
	this->color = color;
	this->type = type;
}

int Piece::getType() {
	return this->type;
}

void Piece::setType(int type) {
	this->type = type;
}

int Piece::getColor() {
	return this->color;
}

void Piece::setColor(int color) {
	this->color = color;
}

//returned the ascii character used to represent the piece on the console. ' ' for a space, 'O' for a man, 'X' for a king
//based on piece->type
char Piece::charRepresentation() {
	switch (this->type)
	{
	case -1:
		return ' ';
	case -2:
		return 'O';
	case -3:
		return 'X';
	default:
		return 'UHOH';
	}
}

