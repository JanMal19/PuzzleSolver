#pragma once

namespace PuzzleSolver {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form
	{
	public:
		StartForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ IntroGameLabel;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ComboBox^ PlayerComboBox;
	private: System::Windows::Forms::Label^ GameSizeLabel;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::NumericUpDown^ gameSizeUpDown;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->IntroGameLabel = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->PlayerComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->GameSizeLabel = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->gameSizeUpDown = (gcnew System::Windows::Forms::NumericUpDown());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->flowLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gameSizeUpDown))->BeginInit();
			this->SuspendLayout();
			// 
			// IntroGameLabel
			// 
			this->IntroGameLabel->AutoSize = true;
			this->IntroGameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->IntroGameLabel->Location = System::Drawing::Point(173, 9);
			this->IntroGameLabel->Name = L"IntroGameLabel";
			this->IntroGameLabel->Size = System::Drawing::Size(418, 39);
			this->IntroGameLabel->TabIndex = 0;
			this->IntroGameLabel->Text = L"Uk³adanki z lat dziecinnych";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->label1->Location = System::Drawing::Point(15, 0);
			this->label1->Margin = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 26);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Gracz";
			// 
			// PlayerComboBox
			// 
			this->PlayerComboBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->PlayerComboBox->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->PlayerComboBox->FormattingEnabled = true;
			this->PlayerComboBox->Location = System::Drawing::Point(15, 41);
			this->PlayerComboBox->Margin = System::Windows::Forms::Padding(15);
			this->PlayerComboBox->Name = L"PlayerComboBox";
			this->PlayerComboBox->Size = System::Drawing::Size(305, 29);
			this->PlayerComboBox->TabIndex = 3;
			// 
			// GameSizeLabel
			// 
			this->GameSizeLabel->AutoSize = true;
			this->GameSizeLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->GameSizeLabel->Location = System::Drawing::Point(15, 85);
			this->GameSizeLabel->Margin = System::Windows::Forms::Padding(15, 0, 15, 0);
			this->GameSizeLabel->Name = L"GameSizeLabel";
			this->GameSizeLabel->Size = System::Drawing::Size(169, 26);
			this->GameSizeLabel->TabIndex = 4;
			this->GameSizeLabel->Text = L"Rozmiar planszy";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->label1);
			this->flowLayoutPanel1->Controls->Add(this->PlayerComboBox);
			this->flowLayoutPanel1->Controls->Add(this->GameSizeLabel);
			this->flowLayoutPanel1->Controls->Add(this->gameSizeUpDown);
			this->flowLayoutPanel1->Location = System::Drawing::Point(212, 132);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(347, 181);
			this->flowLayoutPanel1->TabIndex = 5;
			// 
			// gameSizeUpDown
			// 
			this->gameSizeUpDown->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->gameSizeUpDown->Location = System::Drawing::Point(15, 126);
			this->gameSizeUpDown->Margin = System::Windows::Forms::Padding(15);
			this->gameSizeUpDown->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 2, 0, 0, 0 });
			this->gameSizeUpDown->Name = L"gameSizeUpDown";
			this->gameSizeUpDown->Size = System::Drawing::Size(305, 29);
			this->gameSizeUpDown->TabIndex = 5;
			this->gameSizeUpDown->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 3, 0, 0, 0 });
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(309, 413);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(141, 37);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Stwórz Gracza";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &StartForm::CreatePlayerButton_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(309, 470);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(141, 37);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Tabela wyników";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(309, 358);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(141, 37);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Rozpocznij gre";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &StartForm::StartGameButton_Click);
			// 
			// StartForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Desktop;
			this->ClientSize = System::Drawing::Size(784, 561);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->IntroGameLabel);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"StartForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Uk³adanki z lat dziecinnych";
			this->Load += gcnew System::EventHandler(this, &StartForm::StartForm_Load);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->gameSizeUpDown))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void StartForm_Load(System::Object^ sender, System::EventArgs^ e);

	private: System::Void CreatePlayerButton_Click(System::Object^ sender, System::EventArgs^ e);

	private: void LoadPlayersToCombobox();

	private: System::Void StartGameButton_Click(System::Object^ sender, System::EventArgs^ e);
};
}
