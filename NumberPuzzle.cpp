#pragma once

#include "pch.h"
#include "NumberPuzzle.h";

using namespace PuzzleSolver;

Button^ NumberPuzzle::CreatePuzzle(GameForm^ gameForm, int number, int initialNumber, bool empty) {
	Button^ btn = gcnew Button();

	btn->Click += gcnew System::EventHandler(gameForm, &GameForm::PuzzleClick);

	btn->Dock = DockStyle::Fill;
	btn->Margin = System::Windows::Forms::Padding(2);
	btn->FlatStyle = FlatStyle::Flat;
	btn->BackColor = System::Drawing::Color::White;

	if (empty) {
		btn->Text = "";
		btn->Tag = "";
	}
	else {
		btn->Text = number.ToString();
		btn->Tag = initialNumber.ToString();
	}

	return btn;
}