#pragma once

#include "pch.h"
#include "GameForm.h"

#include <iostream>

using namespace PuzzleSolver;

class BasePuzzle
{
protected:

public:
    BasePuzzle() { }

    virtual ~BasePuzzle() {}

    virtual Button^ CreatePuzzle(GameForm^ gameForm, int number, int initialNumber, bool empty) = 0;

    virtual bool IsPuzzleInRightPosition(Object^ object) = 0;
};