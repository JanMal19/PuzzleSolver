#pragma once

#include "pch.h"
#include "GameForm.h"

#include <iostream>

using namespace PuzzleSolver;

class BaseBoard
{
protected:
    int BoardSize;


public:
    BaseBoard(int size) : BoardSize(size) {}

    virtual ~BaseBoard() {}

    virtual void CreateBoard(System::Windows::Forms::TableLayoutPanel^ panel, GameForm^ gameForm) = 0;

    int getBoardSize() const { return BoardSize; }

    void SetSize(int size) { BoardSize = size; }
};