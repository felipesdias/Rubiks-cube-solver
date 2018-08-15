#include "Cube.h"

void printCube(int CUBE, int face) {
	std::map<int, std::string> colors;
	std::map<int, std::string> faces;

	colors[YELLOW] = "YELLOW";
	colors[BLUE] = "BLUE  ";
	colors[WHITE] = "WHITE ";
	colors[GREEN] = "GREEN ";
	colors[RED] = "RED   ";
	colors[ORANGE] = "ORANGE";

	faces[UP] = "UP";
	faces[FRONT] = "FRONT";
	faces[DOWN] = "DOWN";
	faces[BACK] = "BACK";
	faces[RIGHT] = "RIGHT";
	faces[LEFT] = "LEFT";

	int iniFace = (face == -1) ? 0 : face;
	int endFace = (face == -1) ? 6 : face + 1;

	for (int i = iniFace; i < endFace; i++) {
		std::cout << faces[i] << ":\n";
		for (int j = 0; j < 3; j++) {
			std::cout << "   ";
			for (int k = 0; k < 3; k++) {
				std::cout << colors[cube[i][j][k]] << "\t";
			}
			std::cout << "\n";
		}
		std::cout << "\n";
	}
}

void initializeCube(int CUBE) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				cube[i][j][k] = i;
			}
		}
	}
}

bool solved(int CUBE) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (cube[i][j][k] != i)
					return false;
			}
		}
	}

	return true;
}

void applyMovement(int CUBE, int movement) {
	switch (movement)
	{
	case RH:
		move::right(cube); break;
	case RA:
		move::right_(cube); break;
	case LH:
		move::left(cube); break;
	case LA:
		move::left_(cube); break;
	case UH:
		move::up(cube); break;
	case UA:
		move::up_(cube); break;
	case DH:
		move::down(cube); break;
	case DA:
		move::down_(cube); break;
	case FH:
		move::front(cube); break;
	case FA:
		move::front_(cube); break;
	case BH:
		move::back(cube); break;
	case BA:
		move::back_(cube); break;
	}
}

std::string intToMove(int movement) {
	switch (movement)
	{
	case RH:
		return "R"; break;
	case RA:
		return "R'"; break;
	case LH:
		return "L"; break;
	case LA:
		return "L'"; break;
	case UH:
		return "U"; break;
	case UA:
		return "U'"; break;
	case DH:
		return "D"; break;
	case DA:
		return "D'"; break;
	case FH:
		return "F"; break;
	case FA:
		return "F'"; break;
	case BH:
		return "B"; break;
	case BA:
		return "B'"; break;
	}
	return "----";
}