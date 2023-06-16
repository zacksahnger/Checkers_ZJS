/*
* Filename: Piece.cpp
* Author: Zachary Sahnger
* Date: 6/14/2023
* Description: This source file contains the implementation of a program that
*/

#include"Piece.h"


Piece::Piece() {
	this->color = -1;
}
Piece::Piece(int color) { //overload for cases with color provided
	this->color = color;
}


int Piece::getColor() {
	return this->color;
}

void Piece::setColor(int color) {
	this->color = color;
}