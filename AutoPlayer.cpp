#include "pch.h"
#include "AutoPlayer.h"

bool AutoPlayer::TrySolveGame(int maxMoves) {

	Board b = game.GetBoard();

	for (int i = 0; i < maxMoves; i++) {
		//1. znajdujemy pusty puzzel

		NumberPuzzle* emptyPuzzel = b.GetEmptyPuzzel();

		//2. zbieramy dost�pne puzzle kt�re mo�emy tutaj wstawi�
		vector<NumberPuzzle*> availablePuzzles = b.GetAvailablePuzzlesForMoveAction(emptyPuzzel->GetCurrentPosition());

		//3. losujemy puzzel kt�ry mo�na przesun��

		std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
		// rozk�ad r�wnomierny w zakresie indeks�w
		std::uniform_int_distribution<int> dist(0, availablePuzzles.size() - 1);
		// losowy indeks
		int index = dist(rng);

		NumberPuzzle* puzzleForMoveAction = availablePuzzles[index];

		//4. przesuwamy puzze;
		b.MovePuzzle(emptyPuzzel->GetCurrentPosition(), puzzleForMoveAction->GetCurrentPosition());

		//5 sprawdzamy czy uda�o si� u�o�y� puzzle
		if (b.isSolved())
			return true;
	}


	return false;
}