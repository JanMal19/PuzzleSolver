#include "pch.h"
#include "StartForm.h"
#include "CreatePlayerForm.h"
#include "TextDatabase.h"
#include <msclr/marshal_cppstd.h>

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

