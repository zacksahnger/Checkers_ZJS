#pragma once //current source file only included once in a single compilation
/*
* Filename: Piece.h
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description: Piece is an abstract class that defines the base attributes/behaviors of a checkers game piece.
*/
#include<vector>
using std::vector;
class Piece {
public:
	vector<int> getPosition();
	void setPosition(vector<int> posiiton);
	int getColor();
	void setColor(int color);
	Piece();
	Piece(int color); //constructor
	Piece(vector<int> position);
	Piece(int color, vector<int> position);

private:
	vector<int> position;
	int color;
};