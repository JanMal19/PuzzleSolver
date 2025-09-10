#include "pch.h"
#include "NumberPuzzle.h"

using namespace std;

string NumberPuzzle::Draw()
{
	if (isEmpty) {
		return "";
	}
	else {
		return "[ " + std::to_string(currentPosition) + " ]";
	}
}