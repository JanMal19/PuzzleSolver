#include "pch.h"
#include "AutoPlayer.h"

bool AutoPlayer::TrySolveGame(int maxMoves) {

	Board b = game.GetBoard();

	for (int i = 0; i < maxMoves; i++) {
		//1. znajdujemy pusty puzzel

		NumberPuzzle* emptyPuzzel = b.GetEmptyPuzzel();

		//2. zbieramy dostêpne puzzle które mo¿emy tutaj wstawiæ
		vector<NumberPuzzle*> availablePuzzles = b.GetAvailablePuzzlesForMoveAction(emptyPuzzel->GetCurrentPosition());

		//3. losujemy puzzel który mo¿na przesun¹æ

		std::mt19937 rng(static_cast<unsigned>(std::time(nullptr)));
		// rozk³ad równomierny w zakresie indeksów
		std::uniform_int_distribution<int> dist(0, availablePuzzles.size() - 1);
		// losowy indeks
		int index = dist(rng);

		NumberPuzzle* puzzleForMoveAction = availablePuzzles[index];

		//4. przesuwamy puzze;
		b.MovePuzzle(emptyPuzzel->GetCurrentPosition(), puzzleForMoveAction->GetCurrentPosition());

		//5 sprawdzamy czy uda³o siê u³o¿yæ puzzle
		if (b.isSolved())
			return true;
	}


	return false;
}