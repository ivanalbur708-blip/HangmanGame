#include "WordManager.h"
#include <iostream>
#include <fstream>

//Розшифровуємо слово за допомогою шифру Цезаря
std::string WordManager::DecryptWord(const std::string& encrypted)
{
	std::string word = encrypted;

	//Перебираємо кожен символ слова
	for (char& c : word)
	{
		//Зсуваємо символи на 3 позиції назад
		if (c >= 'd' && c <= 'z')
		{
			c -= 3;
		}
		//Перехід через початок алфавіту до його кінця 
		else if (c >= 'a' && c <= 'c')
		{
			c += 23;
		}
	}
	return word;
}

//Завантажуємо слова з файлу. Якщо файл відсутній, створюємо його із зашифрованими словами
std::vector<std::string> WordManager::LoadWords()
{
	std::vector<std::string> words;
	std::ifstream file("words.txt");

	//Перевіряємо, чи відкрився файл
	if (!file.is_open())
	{
		//Створюємо файл
		std::ofstream createFile("words.txt");

		if (!createFile.is_open())
		{
			std::cout << "Error: Cannot create words.txt\n";
			return words;
		}

		//Записуємо зашифровані слова у файл
		createFile << "dssoh\n";
		createFile << "edqdqd\n";
		createFile << "frpsxwhu\n";
		createFile << "nhberdug\n";
		createFile << "vfkrro\n";
		createFile << "jdughq\n";
		createFile << "rudqjh\n";

		createFile.close();

		//Повторно відкриваємо файл для читання
		file.open("words.txt");

		if (!file.is_open())
		{
			std::cout << "Error: Cannot read words.txt\n";
			return words;
		}
	}


	std::string encrypted;

	//Зчитуємо, розшифровуємо та додаємо слова до вектора 
	while (file >> encrypted)
	{
		words.push_back(DecryptWord(encrypted));
	}

	//повертаємо список розшифрованих слів
	return words;
}
