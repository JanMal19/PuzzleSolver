#pragma once

#include "Puzzle.h"
#include <string>

using namespace std;

public class NumberPuzzle : public Puzzle {
public: 
	NumberPuzzle(int tPosition, int cPosition, bool _isEmpty)
		: Puzzle(tPosition, cPosition, _isEmpty) { }

	virtual ~NumberPuzzle() {}

	virtual string Draw() override;
};