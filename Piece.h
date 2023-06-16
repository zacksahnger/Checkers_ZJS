#pragma once //current source file only included once in a single compilation
/*
* Filename: Piece.h
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: Piece is a class that represents each piece on the checkerboard
* currently, this class also represents empty spaces, denoted with a 'type' of -1 
*/
#define SPACE -1
#define MAN -2
#define KING -3

#define BLACK 0
#define WHITE 7
#define LIGHTBLUE 9 
#define LIGHTRED 12
#define GRAY 8

class Piece {
public:
	Piece(); //constructor
	Piece(int color); //constructor
	Piece(int type, int color); //constructor
	int getColor();
	void setColor(int color);
	int getType();
	void setType(int type);
	char charRepresentation();


private:
	int color;
	int type;
};