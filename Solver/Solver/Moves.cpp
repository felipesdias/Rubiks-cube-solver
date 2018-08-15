#include "Moves.h"

void getColumn(int CUBE, int face, int column, int values[3]) {
	values[0] = cube[face][0][column];
	values[1] = cube[face][1][column];
	values[2] = cube[face][2][column];
}

void getLine(int CUBE, int face, int line, int values[3]) {
	values[0] = cube[face][line][0];
	values[1] = cube[face][line][1];
	values[2] = cube[face][line][2];
}

void setColumn(int CUBE, int face, int column, int values[3]) {
	cube[face][0][column] = values[0];
	cube[face][1][column] = values[1];
	cube[face][2][column] = values[2];
}

void setLine(int CUBE, int face, int line, int values[3]) {
	cube[face][line][0] = values[0];
	cube[face][line][1] = values[1];
	cube[face][line][2] = values[2];
}

void rotateFace(int CUBE, int face, int clock) {
	int temp[3], aux[3];
	
	switch (clock)
	{
	case CLOCK_WISE:
		getColumn(cube, face, 2, temp);

		getLine(cube, face, 0, aux);
		setColumn(cube, face, 2, aux);

		getColumn(cube, face, 0, aux);
		std::swap(aux[0], aux[2]);
		setLine(cube, face, 0, aux);

		getLine(cube, face, 2, aux);
		setColumn(cube, face, 0, aux);

		std::swap(temp[0], temp[2]);
		setLine(cube, face, 2, temp);
		break;
	case ANTI_CLOCK_WISE:
		getColumn(cube, face, 2, temp);

		getLine(cube, face, 2, aux);
		std::swap(aux[0], aux[2]);
		setColumn(cube, face, 2, aux);

		getColumn(cube, face, 0, aux);
		setLine(cube, face, 2, aux);

		getLine(cube, face, 0, aux);
		std::swap(aux[0], aux[2]);
		setColumn(cube, face, 0, aux);

		setLine(cube, face, 0, temp);
		break;
	}

}

void move::right(int CUBE) {
	int temp[3], aux[3];
	getColumn(cube, FRONT, 2, temp);

	getColumn(cube, DOWN, 2, aux);
	setColumn(cube, FRONT, 2, aux);

	getColumn(cube, BACK, 2, aux);
	setColumn(cube, DOWN, 2, aux);

	getColumn(cube, UP, 2, aux);
	setColumn(cube, BACK, 2, aux);

	setColumn(cube, UP, 2, temp);

	rotateFace(cube, RIGHT, CLOCK_WISE);
}

void move::right_(int CUBE) {
	int temp[3], aux[3];
	getColumn(cube, FRONT, 2, temp);

	getColumn(cube, UP, 2, aux);
	setColumn(cube, FRONT, 2, aux);

	getColumn(cube, BACK, 2, aux);
	setColumn(cube, UP, 2, aux);

	getColumn(cube, DOWN, 2, aux);
	setColumn(cube, BACK, 2, aux);

	setColumn(cube, DOWN, 2, temp);

	rotateFace(cube, RIGHT, ANTI_CLOCK_WISE);
}

void move::left(int CUBE) {
	int temp[3], aux[3];
	getColumn(cube, FRONT, 0, temp);

	getColumn(cube, UP, 0, aux);
	setColumn(cube, FRONT, 0, aux);

	getColumn(cube, BACK, 0, aux);
	setColumn(cube, UP, 0, aux);

	getColumn(cube, DOWN, 0, aux);
	setColumn(cube, BACK, 0, aux);

	setColumn(cube, DOWN, 0, temp);

	rotateFace(cube, LEFT, CLOCK_WISE);
}

void move::left_(int CUBE) {
	int temp[3], aux[3];
	getColumn(cube, FRONT, 0, temp);

	getColumn(cube, DOWN, 0, aux);
	setColumn(cube, FRONT, 0, aux);

	getColumn(cube, BACK, 0, aux);
	setColumn(cube, DOWN, 0, aux);

	getColumn(cube, UP, 0, aux);
	setColumn(cube, BACK, 0, aux);

	setColumn(cube, UP, 0, temp);

	rotateFace(cube, LEFT, ANTI_CLOCK_WISE);
}

void move::up(int CUBE) {
	int temp[3], aux[3];
	getLine(cube, LEFT, 0, temp);

	getLine(cube, FRONT, 0, aux);
	setLine(cube, LEFT, 0, aux);

	getLine(cube, RIGHT, 0, aux);
	setLine(cube, FRONT, 0, aux);

	getLine(cube, BACK, 2, aux);
	std::swap(aux[0], aux[2]);
	setLine(cube, RIGHT, 0, aux);

	std::swap(temp[0], temp[2]);
	setLine(cube, BACK, 2, temp);

	rotateFace(cube, UP, CLOCK_WISE);
}

void move::up_(int CUBE) {
	int temp[3], aux[3];
	getLine(cube, RIGHT, 0, temp);

	getLine(cube, FRONT, 0, aux);
	setLine(cube, RIGHT, 0, aux);

	getLine(cube, LEFT, 0, aux);
	setLine(cube, FRONT, 0, aux);

	getLine(cube, BACK, 2, aux);
	std::swap(aux[0], aux[2]);
	setLine(cube, LEFT, 0, aux);

	std::swap(temp[0], temp[2]);
	setLine(cube, BACK, 2, temp);

	rotateFace(cube, UP, ANTI_CLOCK_WISE);
}

void move::down(int CUBE)
{
	int temp[3], aux[3];
	getLine(cube, RIGHT, 2, temp);

	getLine(cube, FRONT, 2, aux);
	setLine(cube, RIGHT, 2, aux);

	getLine(cube, LEFT, 2, aux);
	setLine(cube, FRONT, 2, aux);

	getLine(cube, BACK, 0, aux);
	std::swap(aux[0], aux[2]);
	setLine(cube, LEFT, 2, aux);

	std::swap(temp[0], temp[2]);
	setLine(cube, BACK, 0, temp);

	rotateFace(cube, DOWN, CLOCK_WISE);
}

void move::down_(int CUBE)
{
	int temp[3], aux[3];
	getLine(cube, LEFT, 2, temp);

	getLine(cube, FRONT, 2, aux);
	setLine(cube, LEFT, 2, aux);

	getLine(cube, RIGHT, 2, aux);
	setLine(cube, FRONT, 2, aux);

	getLine(cube, BACK, 0, aux);
	std::swap(aux[0], aux[2]);
	setLine(cube, RIGHT, 2, aux);

	std::swap(temp[0], temp[2]);
	setLine(cube, BACK, 0, temp);

	rotateFace(cube, DOWN, ANTI_CLOCK_WISE);
}

void move::front(int CUBE)
{
	int temp[3], aux[3];
	getColumn(cube, RIGHT, 0, temp);

	getLine(cube, UP, 2, aux);
	setColumn(cube, RIGHT, 0, aux);

	getColumn(cube, LEFT, 2, aux);
	std::swap(aux[0], aux[2]);
	setLine(cube, UP, 2, aux);

	getLine(cube, DOWN, 0, aux);
	setColumn(cube, LEFT, 2, aux);

	std::swap(temp[0], temp[2]);
	setLine(cube, DOWN, 0, temp);

	rotateFace(cube, FRONT, CLOCK_WISE);
}

void move::front_(int CUBE)
{
	int temp[3], aux[3];
	getColumn(cube, RIGHT, 0, temp);

	getLine(cube, DOWN, 0, aux);
	std::swap(aux[0], aux[2]);
	setColumn(cube, RIGHT, 0, aux);

	getColumn(cube, LEFT, 2, aux);
	setLine(cube, DOWN, 0, aux);

	getLine(cube, UP, 2, aux);
	std::swap(aux[0], aux[2]);
	setColumn(cube, LEFT, 2, aux);

	setLine(cube, UP, 2, temp);

	rotateFace(cube, FRONT, ANTI_CLOCK_WISE);
}

void move::back(int CUBE)
{
	int temp[3], aux[3];
	getColumn(cube, RIGHT, 2, temp);

	getLine(cube, DOWN, 2, aux);
	std::swap(aux[0], aux[2]);
	setColumn(cube, RIGHT, 2, aux);

	getColumn(cube, LEFT, 0, aux);
	setLine(cube, DOWN, 2, aux);

	getLine(cube, UP, 0, aux);
	std::swap(aux[0], aux[2]);
	setColumn(cube, LEFT, 0, aux);

	setLine(cube, UP, 0, temp);

	rotateFace(cube, BACK, CLOCK_WISE);
}

void move::back_(int CUBE)
{
	int temp[3], aux[3];
	getColumn(cube, RIGHT, 2, temp);

	getLine(cube, UP, 0, aux);
	setColumn(cube, RIGHT, 2, aux);

	getColumn(cube, LEFT, 0, aux);
	std::swap(aux[0], aux[2]);
	setLine(cube, UP, 0, aux);

	getLine(cube, DOWN, 2, aux);
	setColumn(cube, LEFT, 0, aux);

	std::swap(temp[0], temp[2]);
	setLine(cube, DOWN, 2, temp);

	rotateFace(cube, BACK, ANTI_CLOCK_WISE);
}
