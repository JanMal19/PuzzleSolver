#include "pch.h"
#include "CreatePlayerForm.h"
#include "Player.h"
#include  "MarshalStringUtils.h"
#include "TextDatabase.h"

using namespace PuzzleSolver;

CreatePlayerForm::CreatePlayerForm(void) {
	InitializeComponent();
}

CreatePlayerForm::~CreatePlayerForm() {
	if (components)
	{
		delete components;
	}
}

System::Void CreatePlayerForm::SavePlayerButton_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ managedText = gcnew String(playerNameTextBox->Text);
	std::string nativeText = "TestowaNazwa";
	MarshalStringUtils::MarshalString(managedText, nativeText);

	Player p = Player(nativeText);

	bool save = TextDatabase::SavePlayerToDatabase(p);
	if (save) {
		this->Close();
	}
}