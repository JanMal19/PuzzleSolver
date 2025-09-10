#pragma once

#include "NumberPuzzle.h" // albo bazowy Puzzle
#include "MarshalStringUtils.h"
#include <vcclr.h> // dzi�ki temu mog� korzysta� z klasy ref w zwyk�ej klasie

using namespace System;
using namespace System::Windows::Forms;

class PuzzleButton {
private:
    gcroot<System::Windows::Forms::Button^> button;
    NumberPuzzle* puzzle;

public:
    Button^ getButton() { return button; }
    NumberPuzzle* getPuzzle() { return puzzle; }
    ~PuzzleButton() { }

    PuzzleButton(NumberPuzzle* nativePuzzle);

    void UpdateText();

private:
};