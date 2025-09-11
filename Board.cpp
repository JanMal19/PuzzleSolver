#pragma once

#include "pch.h"
#include "NumberPuzzle.h"
#include "Board.h"
#include <cmath>

Board::Board(int n) : size(n) {
    puzzles.reserve(n * n);
}

Board::Board() : Board(3) {

}

void Board::addPuzzle(unique_ptr<NumberPuzzle> p) {
    puzzles.push_back(move(p));
}

bool Board::isSolved() const {
    for (const auto& p : puzzles) {
        if (!p->IsPuzzleInRightPosition())
            return false;
    }
    return true;
}

const vector<unique_ptr<NumberPuzzle>>& Board::getPuzzles() const {
    return puzzles;
}

bool Board::MovePuzzle(int currentPostiion, int targetPosition) {
    Puzzle* movedPuzzle = FindByCurrentPosition(currentPostiion);
    Puzzle* targetPuzzle = FindByCurrentPosition(targetPosition);

    if (movedPuzzle != nullptr && targetPuzzle != nullptr) {
        if (targetPuzzle->IsEmpty()) {
            movedPuzzle->SetCurrentPosition(targetPosition);
            targetPuzzle->SetCurrentPosition(currentPostiion);
            return true;
        }
    }

    return false;
}

NumberPuzzle* Board::FindByCurrentPosition(int pos) {
    for (auto& p : puzzles) {
        if (p->GetCurrentPosition() == pos) {
            return p.get();
        }
    }
    return nullptr;
}

NumberPuzzle* Board::GetEmptyPuzzel() {
    int emptyTarget = size * size;
    for (auto& p : puzzles) {
        if (p->GetTargetPosition() == emptyTarget) {
            return p.get();
        }
    }
    return nullptr;
}

vector<NumberPuzzle*> Board::GetAvailablePuzzlesForMoveAction(int puzzlePosition) {

    std::vector<NumberPuzzle*> puzzlesAvailable;

    for (auto& p : puzzles) {
        if (CanSwapPositions(p->GetCurrentPosition(), puzzlePosition)) {
            puzzlesAvailable.push_back(p.get());
        }
    }

    return puzzlesAvailable;
}

bool Board::CanSwapPositions(int a, int b) {
    if (a == b)
        return false;

    int rowA = (a - 1) / size;
    int colA = (a - 1) % size;

    int rowB = (b - 1) / size;
    int colB = (b - 1) % size;

    return (std::abs(rowA - rowB) + std::abs(colA - colB)) == 1;
}