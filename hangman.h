#ifndef HANGMAN_H_
#define HANGMAN_H_

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

class hangman
{
public:
    static void start();
private:
    static std::string rand_word();
    static int numWords();
    static void show_board(int);
    static char getGuess();
    static std::string handleGuess(char);
};

#endif