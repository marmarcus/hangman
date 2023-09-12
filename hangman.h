#ifndef HANGMAN_H_
#define HANGMAN_H_

#include <iostream>
#include <fstream>
#include <string>

class hangman{
public:
    void start();
private:
    std::string answer;
    std::string guess;

    char letter;

    int lives = 6;

    bool win = false;
    bool lose = false;

    void randWord();
    int numWords();
    void initialize();
    void showBoard();
    void getGuess();
    void handleGuess();

};

#endif