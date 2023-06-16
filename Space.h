#pragma once
/*
* Filename: Piece.h
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: Space is a class that defines the base attributes/behaviors of a space on a checkers game board.
*/
class Space {
public:
	Space();
	Space(int color); //constructor
	bool canMoveForwards();
	bool canMoveBackwards();
	char pieceRepresentation();
private:
	int color; //doesn't really matter
};