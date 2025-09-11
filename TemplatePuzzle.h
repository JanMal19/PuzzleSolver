#pragma once
#include <string>

template<typename T>
class TemplatePuzzle
{
protected:
    T targetPosition;
    T currentPosition;

public:
    TemplatePuzzle(const T& tPosition, const T& cPosition)
        : targetPosition(tPosition), currentPosition(cPosition) {}

    virtual ~TemplatePuzzle() {}

    bool IsPuzzleInRightPosition() const {
        return targetPosition == currentPosition;
    }

    void SetCurrentPosition(const T& cP) {
        currentPosition = cP;
    }

    virtual std::string Draw() = 0;

    inline T GetCurrentPosition() const { return currentPosition; }
    inline T GetTargetPosition() const { return targetPosition; }
};
