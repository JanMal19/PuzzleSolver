#include "pch.h"
#include "FinishForm.h"

using namespace PuzzleSolver;

FinishForm::FinishForm(void) {
	InitializeComponent();
}

FinishForm::~FinishForm() {
	if (components)
	{
		delete components;
	}
}

System::Void FinishForm::EndGame_Click(System::Object^ sender, System::EventArgs^ e) {
	this->DialogResult = System::Windows::Forms::DialogResult::Abort;
	this->Close();
}

System::Void FinishForm::PlayAgain_Click(System::Object^ sender, System::EventArgs^ e) {
	this->DialogResult = System::Windows::Forms::DialogResult::OK;
	this->Close();
}