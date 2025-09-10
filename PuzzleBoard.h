#pragma once

#include "pch.h"
#include "NumberHelper.h"
#include "GameForm.h"
#include "Puzzle.h"

#include <vector>

using namespace std;

public class PuzzleBoard {
    int size;
    vector<unique_ptr<Puzzle>> puzzles;

public:
    PuzzleBoard(int n);

    ~PuzzleBoard() = default;

    void addPuzzle(unique_ptr<Puzzle> p);

    bool isSolved() const;

    const vector<unique_ptr<Puzzle>>& getPuzzles() const;

};