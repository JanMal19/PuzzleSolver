#pragma once

#include "pch.h"
#include "Game.h"

Game::Game(Player _player, int _size) : player(_player), size(_size), puzzleBoard(_size) {
	InitBoard();
}


void Game::SaveResultToDatabase(int time) {

}

void Game::InitBoard() {
	std::vector<int> numbers = NumberHelper::generateShuffledNumbers(size);

	int index = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			bool isEmpty = i == size - 1 && j == size - 1;

			int randomNumber = 0;
			if (!isEmpty) {
				randomNumber = numbers[index];
			}
			else {
				randomNumber = size * size;
			}
			index++;

			NumberPuzzle numberPuzzle = NumberPuzzle(index, randomNumber, isEmpty);
			puzzleBoard.addPuzzle(std::make_unique<NumberPuzzle>(numberPuzzle));
		}
	}
}

bool Game::MovePuzzle(int currentPosition, int targetPosition) {
	return puzzleBoard.MovePuzzle(currentPosition, targetPosition);
}