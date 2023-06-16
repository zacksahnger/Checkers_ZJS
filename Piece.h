#pragma once //current source file only included once in a single compilation
/*
* Filename: Piece.h
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: Piece is a class that defines the base attributes/behaviors of a checkers base game piece.
*/
#include "Space.h"

class Piece : Space {
public:
	
	Piece();
	Piece(int color); //constructor
	int getColor();
	void setColor(int color);
	bool canMoveForwards();
	bool canMoveBackwards();
	char pieceRepresentation();

private:
	int color;
};