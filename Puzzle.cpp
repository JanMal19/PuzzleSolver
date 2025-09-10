#pragma once

#include "pch.h"
#include "Puzzle.h"

bool Puzzle::IsPuzzleInRightPosition() {
	return targetPosition == currentPosition;
}

void Puzzle::SetCurrentPosition(int cP) {
	currentPosition = cP;
}