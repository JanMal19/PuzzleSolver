#pragma once

#include "pch.h"
#include "Game.h"

#include <vector>

class AutoPlayer {
private:
	Game& game;

public:
	AutoPlayer(Game& g) : game(g) {};

	bool TrySolveGame(int maxMoves);
};