#pragma once

#include "pch.h"
#include "NumberHelper.h"
#include "NumberPuzzle.h"

#include <vector>

using namespace std;

class Board {
    int size;
    vector<unique_ptr<NumberPuzzle>> puzzles;

public:

    Board(int n);

    Board();

    ~Board() = default;

    void addPuzzle(unique_ptr<NumberPuzzle> p);

    bool isSolved() const;

    const vector<unique_ptr<NumberPuzzle>>& getPuzzles() const;

    bool MovePuzzle(int currentPostiion, int targetPosition);

    NumberPuzzle* FindByCurrentPosition(int pos);

    NumberPuzzle* GetEmptyPuzzel();

    vector<NumberPuzzle*> GetAvailablePuzzlesForMoveAction(int puzzlePosition);

    bool CanSwapPositions(int a, int b);
};