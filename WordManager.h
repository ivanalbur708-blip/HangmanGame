#pragma once
#include <string>
#include <vector>

class WordManager
{
private:
	std::string DecryptWord(const std::string& encrypted);
public:
	std::vector<std::string> LoadWords();

};

