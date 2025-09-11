#pragma once

#include "pch.h"
#include <vector>

#include <iostream>

public class Puzzle
{
protected:
    int targetPosition;
    int currentPosition;
    bool isEmpty;

public:
    Puzzle(int tPosition, int cPosition, bool _isEmpty) : targetPosition(tPosition), currentPosition(cPosition), isEmpty(_isEmpty) { }

    virtual ~Puzzle() {}

    bool IsPuzzleInRightPosition();
    
    void SetCurrentPosition(int cP);

    virtual std::string Draw() = 0;

    inline int GetCurrentPosition() { return currentPosition; }

    inline int GetTargetPosition() { return targetPosition; }

    inline bool IsEmpty() { return isEmpty; }

    inline void SetIsEmpty(bool _isEmpty) { isEmpty = _isEmpty; }
};