/*
* Filename: Space.cpp
* Author: Zachary Sahnger
* Date: 6/15/2023
* Description:
*/
#include "Space.h"

Space::Space() {
	this->color = -1;
}
Space::Space(int color){
	this->color = color;
}

bool Space::canMoveForwards() {
	return false;
}

bool Space::canMoveBackwards() {
	return false;
}
char Space::pieceRepresentation(){
	return ' ';
}

int Space::getColor() {
	return this->color;
}