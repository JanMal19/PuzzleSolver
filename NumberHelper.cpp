#include "pch.h"
#include "NumberHelper.h"

std::vector<int> NumberHelper::generateShuffledNumbers(int n)
{
	std::vector<int> numbers;
	numbers.reserve(n * n - 1);

	for (int i = 1; i < n * n; i++)
	{
		numbers.push_back(i);
	}

	// generator losowy
	std::random_device rd;
	std::mt19937 g(rd());

	// przetasowanie
	std::shuffle(numbers.begin(), numbers.end(), g);

	return numbers;
}