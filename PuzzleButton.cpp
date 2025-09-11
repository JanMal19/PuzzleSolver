#include "pch.h"
#include "PuzzleButton.h"
#include "NumberPuzzle.h"

PuzzleButton::PuzzleButton(NumberPuzzle* nativePuzzle) : puzzle(nativePuzzle) {
    button = gcnew Button();
    button->Dock = DockStyle::Fill;
    button->Margin = System::Windows::Forms::Padding(1);
    button->FlatStyle = FlatStyle::Flat;
    button->BackColor = System::Drawing::Color::White;

    if (puzzle != nullptr) {
        button->Text = gcnew System::String(puzzle->Draw().c_str());
    }

    button->Tag = IntPtr(puzzle);
}

void PuzzleButton::UpdateText() {
    if (puzzle != nullptr) {
        button->Text = gcnew System::String(puzzle->Draw().c_str());
    }
}