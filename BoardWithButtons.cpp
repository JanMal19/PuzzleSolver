#include "pch.h"
#include "BoardWithButtons.h"
#include "NumberPuzzle.h"

void BoardWithButtons::CreateBoard(System::Windows::Forms::TableLayoutPanel^ gameMap, GameForm^ gameForm)
{

	gameMap->SuspendLayout();

	gameMap->Controls->Clear();

	gameMap->ColumnStyles->Clear();

	gameMap->RowStyles->Clear();

	gameMap->ColumnCount = BoardSize;

	gameMap->RowCount = BoardSize;

	for (int i = 0; i < BoardSize; i++)
	{
		gameMap->ColumnStyles->Add(gcnew ColumnStyle(SizeType::Percent, 100.0f / BoardSize));
		gameMap->RowStyles->Add(gcnew RowStyle(SizeType::Percent, 100.0f / BoardSize));
	}

	std::vector<int> numbers = NumberHelper::generateShuffledNumbers(BoardSize);

	int index = 0;
	for (int i = 0; i < BoardSize; i++) {
		for (int j = 0; j < BoardSize; j++) {
			NumberPuzzle puzzle = NumberPuzzle();

			bool isEmpty = i == BoardSize - 1 && j == BoardSize - 1;

			int randomNumber = 0;
			if (!isEmpty) {
				randomNumber = numbers[index];
				index++;
			}
			else {
				randomNumber = 0;
			}

			Button^ btn = puzzle.CreatePuzzle(gameForm, randomNumber, 1 + index, isEmpty);

			gameMap->Controls->Add(btn, j, i);
		}
	}

	gameMap->ResumeLayout();
}