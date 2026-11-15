#include "Game.h"
#include "WordManager.h"
#include "GameStatistics.h"
#include <iostream>
#include <chrono>

void Game::Run()
{
	//Завантажуємо список слів із файлу
	WordManager manager;
	std::vector<std::string> words = manager.LoadWords();


	//Перевірка, чи є доступні слова для гри
	if (words.empty())
	{
		std::cout << "No words available\n";
		return;
	}


	//Ініціалізуємо генератор випадкових чисел
	std::srand(time(nullptr));

	//Випадковим чином вибраємо слово із списку
	int index = std::rand() % words.size();

	secretWord = words[index];

	//Замінюємо всі літери на _
	guessedWord.assign(secretWord.size(), '_');

	//Починаємо підрахунок помилок та часу гри
	int mistakes = 0;
	auto start = std::chrono::steady_clock::now();

	//Гра триває, поки слово не вгадано або не вичерпано спроби
	while (guessedWord != secretWord && mistakes < maxMistakes)
	{
		std::cout << "Word: " << guessedWord << '\n';
		std::cout << "Mistakes left: " << maxMistakes - mistakes << '\n';

		//Отримуємо літеру 
		char letter;
		std::cout << "Enter a letter: ";
		std::cin >> letter;

		//Перевіряємо, чи вводив гравець цю літеру раніше 
		bool alreadyGuessed = false;
		for (char c : guessedLetters)
		{
			if (c == letter) { alreadyGuessed = true; }
		}
		//Якщо літера вже була, не зараховуємо спробу
		if (alreadyGuessed)
		{
			std::cout << "You already guessed this letter!\n";
			continue;
		}

		//Зберігаемо введену літеру в загаданому слові
		guessedLetters.push_back(letter);
		attempts++;

		bool found = false;
		for (std::size_t i = 0;i < secretWord.size();i++)
		{
			if (letter == secretWord[i])
			{
				//Відкриваемо зайндену літеру у слові
				guessedWord[i] = letter;
				found = true;
			}
		}
		//Якщо літеру не знайдено, збільшуємо кількість помилок
		if (!found) mistakes++;
		

	}
	//Завершуємо вимірювання часу гри
	auto end = std::chrono::steady_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

	//Визначаємо результат гри
	if (guessedWord == secretWord)
	{
		std::cout << "You win!\n";
	}
	else
	{
		std::cout << "You lose!\n";
	}

	//Створюємо  об'єкт стастики гри
	GameStatistics stats(duration, attempts, secretWord, guessedLetters);

	//Виводимо статистику на екран та зберігаємо у файл
	stats.ShowStatistics();
	stats.SaveStatistics();
}