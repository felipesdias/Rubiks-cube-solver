#include "FindSetup.h"

void findSetup(int CUBE, int *movements, int max_moves, int step, int lastMove) {
	if (solved(cube)) {
		movements[step] = -1;
		
		std::cout << "\t";
		for (int i = 0; i <= max_moves; i++) {
			if (movements[i] == -1) {
				std::cout << "- Number of movements: " << i << std::endl;
				break;
			}

			std::cout << intToMove(movements[i]) << " ";
		}

		return;
	}

	if (max_moves == step) {
		return;
	}

	for (int i = 0; i < 12; i++) {
		if (step == 0)
			std::cout << "Inicio movimento: " << intToMove(i) << "\n";

		if (i % 2) {
			if (lastMove == i || lastMove + 1 == i)
				continue;
		}
		else if (lastMove - 1 == i) {
			continue;
		}
		
		if (i / 4 == lastMove / 4 && i > lastMove && i % 4 > 1) {
			continue;
		}

		movements[step] = i;

		applyMovement(cube, i);
		findSetup(cube, movements, max_moves, step + 1, i);
		applyMovement(cube, i + (i % 2 ? -1 : 1));
	}

	return;
}