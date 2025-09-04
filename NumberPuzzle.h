#pragma once

#include "pch.h"
#include "BasePuzzle.h"
#include "GameForm.h"
#include <vector>

using namespace System::Windows::Forms;
using namespace PuzzleSolver;


class NumberPuzzle : public BasePuzzle
{
public:
    NumberPuzzle() : BasePuzzle() {}

    virtual Button^ CreatePuzzle(GameForm^ gameForm, int number, int initialNumber, bool empty) override;
};