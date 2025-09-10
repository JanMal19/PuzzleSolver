#pragma once

#include "TemplatePuzzle.h"

class NumberPuzzleT : public TemplatePuzzle<int>
{
    int number;

public:
    NumberPuzzleT(int num, int tPos, int cPos)
        : TemplatePuzzle<int>(tPos, cPos), number(num) {}

    std::string Draw() override {
        return std::to_string(number);
    }
};