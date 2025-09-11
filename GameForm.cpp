#include "pch.h"
#include "GameForm.h"
#include "NumberHelper.h"
#include "FinishForm.h"
#include "PuzzleButton.h"
#include "NumberPuzzle.h"
#include "Game.h"

using namespace PuzzleSolver;

GameForm::GameForm(Game* _game) {
	InitializeComponent();
	game = _game;
	game->InitBoard();
	InitializeGameMap();
}

GameForm::GameForm() {
	InitializeComponent();
}

GameForm::~GameForm() {
	if (components)
	{
		delete components;
	}
}

System::Void GameForm::GameForm_Closed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	if (this->DialogResult != System::Windows::Forms::DialogResult::Abort) {
		this->DialogResult = System::Windows::Forms::DialogResult::OK;
	}
}

void GameForm::InitializeGameMap() {
	puzzleButtons = gcnew System::Collections::Generic::List<PuzzleButtonWrapper^>();

	puzzleSize = game->GetSize();

	gameMap->SuspendLayout();

	gameMap->Controls->Clear();

	gameMap->ColumnStyles->Clear();

	gameMap->RowStyles->Clear();

	gameMap->ColumnCount = puzzleSize;

	gameMap->RowCount = puzzleSize;

	for (int i = 0; i < puzzleSize; i++)
	{
		gameMap->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 100.0f / puzzleSize));
		gameMap->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 100.0f / puzzleSize));
	}

	int index = 1;
	for (int i = 0; i < puzzleSize; i++) {
		for (int j = 0; j < puzzleSize; j++) {

			NumberPuzzle* nativePuzzle = game->GetBoard().FindByCurrentPosition(index);

			PuzzleButton* puzzleButton = new PuzzleButton(nativePuzzle);
			PuzzleButtonWrapper^ wrapper = gcnew PuzzleButtonWrapper(puzzleButton);

			wrapper->ButtonControl->Click += gcnew System::EventHandler(this, &GameForm::PuzzleClick);

			puzzleButtons->Add(wrapper);

			gameMap->Controls->Add(wrapper->ButtonControl, j, i);

			index++;
		}
	}

	gameMap->ResumeLayout();
}


System::Void GameForm::GameTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	elapsedSeconds++;
	timeCounterValueLabel->Text = "Czas gry: " + elapsedSeconds.ToString() + " s";
}

System::Void GameForm::GameForm_Load(System::Object^ sender, System::EventArgs^ e) {
	gameTimer->Start();
}

System::Void GameForm::PuzzleClick(System::Object^ sender, System::EventArgs^ e) {

	if (clickedButton != nullptr) {
		clickedButton->BackColor = System::Drawing::Color::White;
	}

	clickedButton = dynamic_cast<System::Windows::Forms::Button^>(sender);

	if (clickedButton != nullptr) {
		clickedButton->BackColor = System::Drawing::Color::GreenYellow;
	}

}


System::Void GameForm::RestartGame_Click(System::Object^ sender, System::EventArgs^ e) {
	game->InitBoard();
	elapsedSeconds = 0;
}

Button^ GameForm::FindEmptyButton()
{
	for each (Control ^ ctrl in this->gameMap->Controls)
	{
		Button^ btn = dynamic_cast<Button^>(ctrl);
		if (btn != nullptr && btn->Text == "")
			return btn;
	}
	return nullptr;
}

int GameForm::GetClickedRow() {
	return gameMap->GetRow(clickedButton);
}

int GameForm::GetClickedColumn() {
	return gameMap->GetColumn(clickedButton);
}

PuzzleButtonWrapper^ GameForm::FindWrapperByPuzzle(NumberPuzzle* target)
{
	for each (PuzzleButtonWrapper ^ wrapper in puzzleButtons)
	{
		PuzzleButton* nativePb = wrapper->GetNative();
		Puzzle* puzzle = nativePb->getPuzzle();

		if (puzzle == target) {
			return wrapper;
		}
	}
	return nullptr;
}

void GameForm::SetClickedButtonTextAndColor(Button^ emptyButton) {
	// Emptu Button - jest to obecnie pusty przycisk - tam chcemy przenieœæ obecnie wybrany puzzel
	if (emptyButton != nullptr) {

		System::IntPtr ptr = safe_cast<System::IntPtr>(clickedButton->Tag); // klikniêty puzzel

		NumberPuzzle* puzzle = static_cast<NumberPuzzle*>(ptr.ToPointer());

		// Klikneliœmy pusty puzzel
		if (puzzle->IsEmpty())
			return;

		System::IntPtr ptrEmpty = safe_cast<System::IntPtr>(emptyButton->Tag);

		NumberPuzzle* puzzleEmpty = static_cast<NumberPuzzle*>(ptrEmpty.ToPointer());

		int puzzleEmptyPosition = puzzleEmpty->GetCurrentPosition();
		puzzleEmpty->SetCurrentPosition(puzzle->GetCurrentPosition());
		puzzle->SetCurrentPosition(puzzleEmptyPosition);

		puzzleEmpty->SetIsEmpty(false);
		puzzle->SetIsEmpty(true);


		PuzzleButtonWrapper^ puzzleWraper = FindWrapperByPuzzle(puzzle);
		puzzleWraper->GetNative()->UpdateText();

		PuzzleButtonWrapper^ puzzleEmptyWraper = FindWrapperByPuzzle(puzzleEmpty);
		puzzleEmptyWraper->GetNative()->UpdateText();


		//// Aktualizacja kolorów
		clickedButton->BackColor = System::Drawing::Color::White;
		clickedButton = emptyButton;
		clickedButton->BackColor = System::Drawing::Color::GreenYellow;

		CheckWin();
	}
}

System::Void GameForm::UpButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MoveClickedButton(-1, 0);
}

System::Void GameForm::DownButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MoveClickedButton(1, 0);
}

System::Void GameForm::RightButton_Clicked(System::Object^ sender, System::EventArgs^ e) {
	MoveClickedButton(0, 1);
}

System::Void GameForm::LeftButton_Click(System::Object^ sender, System::EventArgs^ e) {
	MoveClickedButton(0, -1);
}

System::Void GameForm::MoveClickedButton(int deltaRow, int deltaCol)
{
	int row = gameMap->GetRow(clickedButton);
	int col = gameMap->GetColumn(clickedButton);

	int newRow = row + deltaRow;
	int newCol = col + deltaCol;

	if (newRow >= 0 && newRow < gameMap->RowCount &&
		newCol >= 0 && newCol < gameMap->ColumnCount)
	{
		Control^ ctrl = gameMap->GetControlFromPosition(newCol, newRow);
		Button^ btn = dynamic_cast<Button^>(ctrl);
		SetClickedButtonTextAndColor(btn);
	}
}

void GameForm::CheckWin() {
	for each (PuzzleButtonWrapper ^ wrapper in puzzleButtons)
	{
		PuzzleButton* nativePb = wrapper->GetNative();
		Puzzle* puzzle = nativePb->getPuzzle();

		if (!puzzle->IsPuzzleInRightPosition())
		{
			return;
		}
	}

	FinishForm^ finishForm;
	finishForm = gcnew PuzzleSolver::FinishForm();
	finishForm->ShowDialog();

	this->DialogResult = finishForm->DialogResult;
	this->Close();
}