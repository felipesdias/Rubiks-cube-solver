#pragma once
#include <map>
#include <iostream>
#include <string>
#include "Defines.h"
#include "Moves.h"

void printCube(int CUBE, int face = -1);

void initializeCube(int CUBE);

bool solved(int CUBE);

void applyMovement(int CUBE, int movement);

std::string intToMove(int movement);