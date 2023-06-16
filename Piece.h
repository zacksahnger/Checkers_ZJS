#pragma once //current source file only included once in a single compilation
/*
* Filename: Piece.h
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: Piece is an abstract class that defines the base attributes/behaviors of a checkers game piece.
*/

class Piece {
public:
	Piece();
	Piece(int color); //constructor
	int getColor();
	void setColor(int color);


private:
	int color;
	int type;
};