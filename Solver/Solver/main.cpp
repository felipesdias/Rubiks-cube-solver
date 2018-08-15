#include <memory> 
#include <iostream> 
#include <map>
#include <string>
#include <time.h>
#include "Moves.h"
#include "Defines.h"
#include "Util.h"
#include "FindSetup.h"

void aplyMoves(int CUBE, std::string setupMove);

int main()
{	
	srand(time(NULL));
	int CUBE;
	initializeCube(cube);
	
	// printCube(cube);
	// aplyMoves(cube, "R R D R' U U R D' R' U U R'");
	// std::cout << "Next" << std::endl;
	// aplyMoves(cube, "R R D R' U U R D' R' U U R'");
	// aplyMoves(cube, "R R D R' U U R D' R' U U R'");
	// aplyMoves(cube, "U D R U' D'");
	// aplyMoves(cube, "R R L L D' D'");
	// aplyMoves(cube, "R U R' U' R' F R R U' R' U' R U R' F'"); // Perm-T
	// aplyMoves(cube, "R' F R' B B R F' R' B' B' R R");
	// aplyMoves(cube, "R' U R' U'");
	// aplyMoves(cube, "R U U R' U' R U U L' U R' U' L");
	// aplyMoves(cube, "R U R' U R U U R'");
	aplyMoves(cube, "L U U L B' U U R L' F");

	int nMoves = 8;
	int *moves = new int[nMoves + 1];
	findSetup(cube, moves, nMoves, 0);

	// printCube(cube);
	
	system("pause");

	delete moves;
	return 0;
}

void aplyMoves(int CUBE, std::string setupMove) {
	std::vector<std::string> moves = sSplit(setupMove, " ");
	for (int i = 0; i < moves.size(); i++) {
		if (moves[i] == "R")
			move::right(cube);
		else if (moves[i] == "R'")
			move::right_(cube);
		else if (moves[i] == "L")
			move::left(cube);
		else if (moves[i] == "L'")
			move::left_(cube);
		else if (moves[i] == "U")
			move::up(cube);
		else if (moves[i] == "U'")
			move::up_(cube);
		else if (moves[i] == "D")
			move::down(cube);
		else if (moves[i] == "D'")
			move::down_(cube);
		else if (moves[i] == "F")
			move::front(cube);
		else if (moves[i] == "F'")
			move::front_(cube);
		else if (moves[i] == "B")
			move::back(cube);
		else if (moves[i] == "B'")
			move::back_(cube);
	}
}