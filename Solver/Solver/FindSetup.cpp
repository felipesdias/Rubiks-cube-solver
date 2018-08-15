#include "FindSetup.h"

struct Solution {
	int max_movements;
	int CUBE;
	int firstMovement;

	void receiveCube(int CUBE) {
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					this->cube[i][j][k] = cube[i][j][k];
	}
};

void findSetup(int CUBE, int *movements, int max_moves, int step, int lastMove) {
	if (solved(cube)) {
		movements[step] = -1;
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

	for (int i = 0; i < AMOUNT_MOVEMENTS; i++) {
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

DWORD WINAPI nodeFind(LPVOID *params) {
	Solution *solution = (Solution*)params;

	applyMovement(solution->cube, solution->firstMovement);

	int *movements = new int[solution->max_movements];
	movements[0] = solution->firstMovement;

	findSetup(solution->cube, movements, solution->max_movements, 1, solution->firstMovement);

	return TRUE;
}

void startFind(int CUBE, int max_movements) {
	if (solved(cube) == true)
		return;

	// Create a mutex with no initial owner

	Solution *solution = new Solution[AMOUNT_MOVEMENTS];
	HANDLE *aThread = new HANDLE[AMOUNT_MOVEMENTS];
	DWORD ThreadID;

	for (int i = 0; i < AMOUNT_MOVEMENTS; i++) {
		solution[i].max_movements = max_movements;
		solution[i].receiveCube(cube);
		solution[i].firstMovement = i;

		aThread[i] = CreateThread(
			NULL,       // default security attributes
			0,          // default stack size
			(LPTHREAD_START_ROUTINE)nodeFind,
			&solution[i],       // no thread function arguments
			0,          // default creation flags
			&ThreadID); // receive thread identifier

		if (aThread[i] == NULL) {
			printf("CreateThread error: %d\n", GetLastError());
			return;
		}
		else {
			std::cout << "Thread #" << i + 1 << " start\n";
		}
	}

	WaitForMultipleObjects(AMOUNT_MOVEMENTS, aThread, TRUE, INFINITE);

	for (int i = 0; i < AMOUNT_MOVEMENTS; i++) {
		CloseHandle(aThread[i]);
		std::cout << "Thread #" << i + 1 << " closed\n";
	}

	delete solution;
	delete aThread;
}
