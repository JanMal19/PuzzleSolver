#pragma once

#include "Puzzle.h"
#include <string>

using namespace std;

public class NumberPuzzle : public Puzzle {
protected:
	bool isEmpty;
public: 
	NumberPuzzle(int tPosition, int cPosition, bool _isEmpty)
		: Puzzle(tPosition, cPosition) , isEmpty(_isEmpty){}

	virtual ~NumberPuzzle() {}

	virtual string Draw() override;

	inline bool IsEmpty() { return isEmpty; }

	inline void SetIsEmpty(bool _isEmpty) { isEmpty = _isEmpty; }
};