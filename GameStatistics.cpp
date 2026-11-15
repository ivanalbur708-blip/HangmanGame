#include "GameStatistics.h"
#include <iostream>
#include <fstream>
GameStatistics::GameStatistics(long long duration, int attempts, const std::string& secretWord, const std::vector<char>& guessedLetters) :
  duration(duration),attempts(attempts),secretWord(secretWord),guessedLetters(guessedLetters){}

void GameStatistics::ShowStatistics() const
{
	std::cout << "\n===== Game Statistics =====\n";
	std::cout << "Time: " << duration << " seconds\n";

	std::cout << "Attempts: " << attempts << '\n';
	std::cout << "Secret Word: " << secretWord << '\n';

	std::cout << "Guessed letters: ";
	for (char c : guessedLetters)
	{
		std::cout << c << ' ';
	}
	std::cout << '\n';
}

void GameStatistics::SaveStatistics() const
{
	std::ofstream file("statistics.txt", std::ios::app);

	//Перевіємо откритя файлу 
	if (!file.is_open())
	{
		std::cout << "Error: Cannot open statistics.txt\n";
		return;
	}
	//Записуємо час, кілкість спроб та загадане слово 
	file << "Time: " << duration << " seconds\n"; 
	file << "Attempts: " << attempts << '\n';
	file << "Secret Word: " << secretWord << '\n';

	//Записуємо віс введені літери 
	file << "Guessed letters: ";
	for (char c : guessedLetters)
	{
		file << c << ' ';
	}

	file << '\n';

	//Відокремлюємо статистику різних ігор 
	file << "--------------------------\n";
}
