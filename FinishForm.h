#pragma once

namespace PuzzleSolver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for FinishForm
	/// </summary>
	public ref class FinishForm : public System::Windows::Forms::Form
	{
	public:
		FinishForm(void);

	protected:
		~FinishForm();
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ GameTimeLabel;
	private: System::Windows::Forms::Button^ playAgainButton;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->GameTimeLabel = (gcnew System::Windows::Forms::Label());
			this->playAgainButton = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(99, 95);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(163, 36);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Gratulacje!";
			// 
			// GameTimeLabel
			// 
			this->GameTimeLabel->AutoSize = true;
			this->GameTimeLabel->Location = System::Drawing::Point(102, 186);
			this->GameTimeLabel->Name = L"GameTimeLabel";
			this->GameTimeLabel->Size = System::Drawing::Size(0, 13);
			this->GameTimeLabel->TabIndex = 1;
			// 
			// playAgainButton
			// 
			this->playAgainButton->Location = System::Drawing::Point(105, 242);
			this->playAgainButton->Name = L"playAgainButton";
			this->playAgainButton->Size = System::Drawing::Size(157, 39);
			this->playAgainButton->TabIndex = 2;
			this->playAgainButton->Text = L"Zagraj jeszcze raz!";
			this->playAgainButton->UseVisualStyleBackColor = true;
			this->playAgainButton->Click += gcnew System::EventHandler(this, &FinishForm::PlayAgain_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(105, 300);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(157, 39);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Koniec";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &FinishForm::EndGame_Click);
			// 
			// FinishForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(384, 361);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->playAgainButton);
			this->Controls->Add(this->GameTimeLabel);
			this->Controls->Add(this->label1);
			this->Name = L"FinishForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Gratulacje";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void EndGame_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void PlayAgain_Click(System::Object^ sender, System::EventArgs^ e);
};
}
