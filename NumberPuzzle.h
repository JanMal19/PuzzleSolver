#pragma once

#include "pch.h"
#include "BasePuzzle.h"
#include "GameForm.h"
#include <vector>

using namespace System::Windows::Forms;
using namespace PuzzleSolver;


class NumberPuzzle : public BasePuzzle
{
private:
    int currentNumber;
    int initialNumber;

public:
    NumberPuzzle() : BasePuzzle() {}

    virtual Button^ CreatePuzzle(GameForm^ gameForm, int number, int initialNumber, bool empty) override;

    virtual bool IsPuzzleInRightPosition(Object^ object) override;
};