/*
* Filename: Piece.cpp
* Author: Zachary Sahnger
* Date: 6/14/2023
* Description: This source file contains the implementation of a program that
*/

#include"Piece.h"
#include <vector>
using std::vector;

Piece::Piece() { //overload for cases without color provided
	this->color = -1;
	this->position.push_back(-1);
	this->position.push_back(-1);
}
Piece::Piece(int color) { //overload for cases without color provided
	this->color = color;
	this->position.push_back(-1);
	this->position.push_back(-1);
}
Piece::Piece(vector<int> position) { //overload for cases without color provided
	this->color = -1;
	this->position = position;
}

Piece::Piece(int color, vector<int> position) { //overload for cases without color provided
	this->color = color;
	this->position = position;
}

vector<int> Piece::getPosition() {
	return this->position;
}
void Piece::setPosition(vector<int> position) {
	this->position = position;
}

int Piece::getColor() {
	return this->color;
}

void Piece::setColor(int color) {
	this->color = color;
}