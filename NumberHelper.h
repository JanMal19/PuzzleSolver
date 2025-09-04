#pragma once

#include <vector>
#include <random>
#include <algorithm> // std::shuffle

public class NumberHelper {
public:
	/// <summary>
	/// Funkcja zwracaj¹ca losow¹ kolejkê liczb od 1 do n * n
	/// </summary>
	/// <param name="n"> Rozmiar planszy puzlli </param>
	/// <returns></returns>
	static std::vector<int> generateShuffledNumbers(int n);
};