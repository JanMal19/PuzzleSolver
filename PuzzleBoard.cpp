#include "pch.h"
#include "PuzzleBoard.h"
#include "NumberPuzzle.h"

PuzzleBoard::PuzzleBoard(int n) : size(n) {
    puzzles.reserve(n * n);
}

void PuzzleBoard::addPuzzle(unique_ptr<Puzzle> p) {
    puzzles.push_back(move(p));
}

bool PuzzleBoard::isSolved() const {
    for (const auto& p : puzzles) {
        if (!p->IsPuzzleInRightPosition())
            return false;
    }
    return true;
}

const vector<unique_ptr<Puzzle>>& PuzzleBoard::getPuzzles() const {
    return puzzles;
}