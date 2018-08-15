#pragma once

#include "Defines.h"
#include "Moves.h"
#include "Cube.h"
#include <mutex>
#include <windows.h>
#include <process.h>

struct Solution;

void startFind(int CUBE, int max_movements);

void findSetup(int CUBE, int *movements, int max_moves, int move_size, int lastMove);

DWORD WINAPI nodeFind(LPVOID *params);