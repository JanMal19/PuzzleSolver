#include "pch.h"
#include "StartForm.h"
#include "CreatePlayerForm.h"
#include "TextDatabase.h"
#include <msclr/marshal_cppstd.h>
#include "GameForm.h"
#include "Board.h"
#include "Game.h"

using namespace PuzzleSolver;

void StartForm::LoadPlayersToCombobox() {
	auto names = TextDatabase::GetPlayers();

	PlayerComboBox->Items->Clear();

	for (const auto& n : names)
	{
		System::String^ managed = msclr::interop::marshal_as<System::String^>(n);
		PlayerComboBox->Items->Add(managed);
	}
}

System::Void StartForm::StartForm_Load(System::Object^ sender, System::EventArgs^ e) {
	LoadPlayersToCombobox();
}


System::Void StartForm::CreatePlayerButton_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();

	CreatePlayerForm^ createPlayerForm;
	createPlayerForm = gcnew PuzzleSolver::CreatePlayerForm();
	createPlayerForm->ShowDialog();

	LoadPlayersToCombobox();

	this->Show();
	

}

System::Void StartForm::StartGameButton_Click(System::Object^ sender, System::EventArgs^ e) {
	if (PlayerComboBox->SelectedItem == nullptr) {
		MessageBox::Show("Wybierz u¿ytkownika który ma zagraæ.");
		return;
	}

	this->Hide();

	int n = Decimal::ToInt32(gameSizeUpDown->Value);

	System::Object^ obj = PlayerComboBox->SelectedItem;
	System::String^ managed = obj->ToString();

	// teraz na std::string
	std::string playerName = msclr::interop::marshal_as<std::string>(managed);

	Player player = Player(playerName);

	Game* game = new Game(player, n);

	GameForm^ gameForm = gcnew PuzzleSolver::GameForm(game);

	gameForm->ShowDialog();

	if (gameForm->DialogResult == System::Windows::Forms::DialogResult::OK) {
		this->Show();
	}
	else {
		this->Close();
	}
}
