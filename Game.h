#pragma once

#include "pch.h"
#include "Board.h"
#include "Player.h"
#include "Puzzle.h"
#include "NumberHelper.h"


class Game {
private:

	Player player;
	int size;
	Board puzzleBoard;

protected:

public:

	Game(Player _player, int _size);

	~Game() = default;

	inline Board& GetBoard() { return puzzleBoard; }

	inline bool CheckWin() { return puzzleBoard.isSolved(); }

	void SaveResultToDatabase(int time);

	inline void ChangePlayer(Player _player) { player = _player; }

	inline int GetSize() { return size; }

	void InitBoard();

	bool MovePuzzle(int currentPosition, int targetPosition);
};