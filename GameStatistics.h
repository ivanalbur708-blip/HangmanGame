#pragma once
#include <string>
#include <vector>

class GameStatistics
{
private:
    long long duration;
    int attempts;
    std::string secretWord;
    std::vector<char> guessedLetters;

public:
    GameStatistics(long long duration, int attempts,
        const std::string& secretWord,
        const std::vector<char>& guessedLetters);

    void ShowStatistics() const;
    void SaveStatistics() const;
};

