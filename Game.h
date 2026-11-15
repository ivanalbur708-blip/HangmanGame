#pragma once
#include  <string>
#include <vector>
class Game
{
private:
	std::string secretWord;
	std::string guessedWord;
	std::vector<char> guessedLetters;
	int attempts = 0;
	int maxMistakes = 6;
public:
	void Run();
};

