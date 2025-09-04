#pragma once

namespace PuzzleSolver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(int size);

	protected:
		~GameForm();
	private: System::Windows::Forms::TableLayoutPanel^ gameMap;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Label^ timeCounterValueLabel;
	private: System::Windows::Forms::Timer^ gameTimer;

	private: System::Windows::Forms::Button^ buttonUp;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button5;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->gameMap = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->timeCounterValueLabel = (gcnew System::Windows::Forms::Label());
			this->gameTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->buttonUp = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// gameMap
			// 
			this->gameMap->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::Single;
			this->gameMap->ColumnCount = 2;
			this->gameMap->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->gameMap->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->gameMap->Dock = System::Windows::Forms::DockStyle::Fill;
			this->gameMap->Location = System::Drawing::Point(0, 0);
			this->gameMap->Name = L"gameMap";
			this->gameMap->RowCount = 2;
			this->gameMap->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->gameMap->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->gameMap->Size = System::Drawing::Size(760, 580);
			this->gameMap->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->gameMap);
			this->panel1->Location = System::Drawing::Point(12, 68);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(760, 580);
			this->panel1->TabIndex = 1;
			// 
			// timeCounterValueLabel
			// 
			this->timeCounterValueLabel->AutoSize = true;
			this->timeCounterValueLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->timeCounterValueLabel->Location = System::Drawing::Point(12, 21);
			this->timeCounterValueLabel->Name = L"timeCounterValueLabel";
			this->timeCounterValueLabel->Size = System::Drawing::Size(0, 22);
			this->timeCounterValueLabel->TabIndex = 3;
			// 
			// gameTimer
			// 
			this->gameTimer->Interval = 1000;
			this->gameTimer->Tick += gcnew System::EventHandler(this, &GameForm::GameTimer_Tick);
			// 
			// buttonUp
			// 
			this->buttonUp->Location = System::Drawing::Point(171, 655);
			this->buttonUp->Name = L"buttonUp";
			this->buttonUp->Size = System::Drawing::Size(75, 23);
			this->buttonUp->TabIndex = 5;
			this->buttonUp->Text = L"Up";
			this->buttonUp->UseVisualStyleBackColor = true;
			this->buttonUp->Click += gcnew System::EventHandler(this, &GameForm::UpButton_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(85, 686);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Left";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &GameForm::LeftButton_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(250, 686);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Right";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &GameForm::RightButton_Clicked);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(171, 726);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Down";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &GameForm::DownButton_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(624, 714);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(148, 35);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Rozwiąż autoamtycznie";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(624, 655);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(148, 35);
			this->button5->TabIndex = 10;
			this->button5->Text = L"Od nowa";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &GameForm::RestartGame_Click);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(784, 761);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->buttonUp);
			this->Controls->Add(this->timeCounterValueLabel);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"GameForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GameForm";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &GameForm::GameForm_Closed);
			this->Load += gcnew System::EventHandler(this, &GameForm::GameForm_Load);
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: 
		int elapsedSeconds = 0;

		int puzzleSize = 0;

		System::Windows::Forms::Button^ clickedButton = nullptr;

		void InitializeGameMap(int size);

	private: 
		System::Void GameForm_Closed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);


		System::Void GameTimer_Tick(System::Object^ sender, System::EventArgs^ e);

		System::Void GameForm_Load(System::Object^ sender, System::EventArgs^ e);

		System::Void PuzzleClick(System::Object^ sender, System::EventArgs^ e);

		System::Void RestartGame_Click(System::Object^ sender, System::EventArgs^ e);

		Button^ FindEmptyButton();

		void CheckWin();

		System::Void UpButton_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void DownButton_Click(System::Object^ sender, System::EventArgs^ e);

		System::Void RightButton_Clicked(System::Object^ sender, System::EventArgs^ e);

		System::Void LeftButton_Click(System::Object^ sender, System::EventArgs^ e);

		int GetClickedRow();

		int GetClickedColumn();

		void SetClickedButtonTextAndColor(Button^ emptyButton);
};
}
