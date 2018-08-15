#pragma once
#include <iostream>
#include "algorithm"
#include "Defines.h"

void getColumn(int CUBE, int face, int column, int values[3]);
void getLine(int CUBE, int face, int line, int values[3]);
void setColumn(int CUBE, int face, int column, int values[3]);
void setLine(int CUBE, int face, int line, int values[3]);
void rotateFace(int CUBE, int face, int clock);

namespace move {
	void right(int CUBE);
	void right_(int CUBE);
	void left(int CUBE);
	void left_(int CUBE);
	void up(int CUBE);
	void up_(int CUBE);
	void down(int CUBE);
	void down_(int CUBE);
	void front(int CUBE);
	void front_(int CUBE);
	void back(int CUBE);
	void back_(int CUBE);
};
