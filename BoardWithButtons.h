#pragma once

#include "BaseBoard.h"
#include "NumberHelper.h"
#include "GameForm.h"
#include "BasePuzzle.h"

#include <vector>

using namespace System::Windows::Forms;
using namespace PuzzleSolver;


class BoardWithButtons : public BaseBoard
{
private:

public:
	BoardWithButtons() : BaseBoard(3) {}

    BoardWithButtons(int size) : BaseBoard(size) {}

    void CreateBoard(System::Windows::Forms::TableLayoutPanel^ gameMap, GameForm^ gameForm) override;
};