#include "pch.h"
#include "GameForm.h"
#include "NumberHelper.h"

using namespace PuzzleSolver;

GameForm::GameForm(int size) {
	InitializeComponent();
	InitializeGameMap(size);
}

GameForm::~GameForm() {
	if (components)
	{
		delete components;
	}
}

System::Void GameForm::GameForm_Closed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e){

}

void GameForm::InitializeGameMap(int size) {
	gameMap->SuspendLayout();

	gameMap->Controls->Clear();

	gameMap->ColumnStyles->Clear();

	gameMap->RowStyles->Clear();

	gameMap->ColumnCount = size;

	gameMap->RowCount = size;

	for (int i = 0; i < size; i++)
	{
		gameMap->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 100.0f / size));
	}

	// wiersze
	for (int i = 0; i < size; i++)
	{
		gameMap->RowStyles->Add(
			gcnew RowStyle(SizeType::Percent, 100.0f / size)
		);
	}

	std::vector<int> numbers = NumberHelper::generateShuffledNumbers(size);
	int index = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			Button^ btn = gcnew Button();

			btn->Click += gcnew System::EventHandler(this, &GameForm::PuzzleClick);

			btn->Dock = DockStyle::Fill;
			btn->Margin = System::Windows::Forms::Padding(2);
			btn->FlatStyle = FlatStyle::Flat;
			btn->BackColor = System::Drawing::Color::White;

			if (i == size - 1 && j == size - 1) {
				btn->Text = "";
			}
			else {
				btn->Text = numbers[index].ToString();
				index++;
			}

			gameMap->Controls->Add(btn, i, j);
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

void GameForm::SetClickedButtonTextAndColor(Button^ emptyButton) {
	if (emptyButton != nullptr && emptyButton->Text == "") {
		emptyButton->Text = clickedButton->Text;
		clickedButton->Text = "";
		clickedButton->BackColor = System::Drawing::Color::White;

		clickedButton = emptyButton;
		clickedButton->BackColor = System::Drawing::Color::GreenYellow;
	}
}

System::Void GameForm::UpButton_Click(System::Object^ sender, System::EventArgs^ e) {

	int row = GetClickedRow();
	int col = GetClickedColumn();

	if (row > 0) {
		Control^ above = gameMap->GetControlFromPosition(col, row - 1);
		Button^ btnAbove = dynamic_cast<Button^>(above);
		SetClickedButtonTextAndColor(btnAbove);
	}

}

System::Void GameForm::DownButton_Click(System::Object^ sender, System::EventArgs^ e) {

	int row = GetClickedRow();
	int col = GetClickedColumn();

	if (row < gameMap->RowCount - 1) {
		Control^ below = gameMap->GetControlFromPosition(col, row + 1);
		Button^ btnBelow = dynamic_cast<Button^>(below);
		SetClickedButtonTextAndColor(btnBelow);
	}

}

System::Void GameForm::RightButton_Clicked(System::Object^ sender, System::EventArgs^ e) {
	int row = GetClickedRow();
	int col = GetClickedColumn();

	if (col < gameMap->ColumnCount - 1) {
		Control^ right = gameMap->GetControlFromPosition(col + 1, row);
		Button^ btnRight = dynamic_cast<Button^>(right);
		SetClickedButtonTextAndColor(btnRight);
	}
}

System::Void GameForm::LeftButton_Click(System::Object^ sender, System::EventArgs^ e) {
	int row = gameMap->GetRow(clickedButton);
	int col = gameMap->GetColumn(clickedButton);

	if (col > 0) {
		Control^ left = gameMap->GetControlFromPosition(col - 1, row);
		Button^ btnLeft = dynamic_cast<Button^>(left);
		SetClickedButtonTextAndColor(btnLeft);
	}
}
