#pragma once

#include "pch.h"
#include <vector>

#include <iostream>

public class Puzzle
{
protected:
    int targetPosition;
    int currentPosition;

public:
    Puzzle(int tPosition, int cPosition) : targetPosition(tPosition), currentPosition(cPosition){}

    virtual ~Puzzle() {}

    bool IsPuzzleInRightPosition();
    
    void SetCurrentPosition(int cP);

    virtual std::string Draw() = 0;

    inline int GetCurrentPosition() { return currentPosition; }
};