#include "hangman.h"

void hangman::start() {
    //variables
    int mode;
    int lives = 6;
    int badAttempts = 0;
    std::string ansWord;
    bool win = false;
    bool lose = false;

    //intro
    std::cout << "\t~~Welcome to Hangman!~~\n" << std::endl;
    std::cout << "Select How You Want To Play:" << std::endl;
    std::cout << "1. Random Word\n2. Custom Word\n" << std::endl;

    std::cin >> mode;
    switch(mode){
        case 1: // Random Word
            ansWord = rand_word();
            break;
        case 2: // Custom Word
            std::cout << "Enter a custom word: ";
            std::cin >> ansWord;
            break;
        default:
            std::cout << "Invalid Option\nProgram Terminating.." << std::endl;
    }
    
    std::cout << "\nStarting Game..\n" << std::endl;

    while(!win && !lose){
        show_board(badAttempts);
        getGuess();
        win = true;
    }
}

//-----------------------------------------------------------------------------------------------------------

std::string hangman::rand_word() {
    std::string word;
    std::ifstream wordFile("words.txt");
    int line;

    srand(time(0));
    line = rand() % numWords();

    while(wordFile.is_open()){
        for(int i = 0; i < line; i++){
            std::getline(wordFile, word);
        }
        wordFile.close();
    }

    return word;
}

int hangman::numWords() {
    std::ifstream wordFile("words.txt");
    if (wordFile.is_open()) {
        std::string line;
        int lineCount = 0;

        while (std::getline(wordFile, line)) {
            lineCount++;
        }

        wordFile.close();
    
        return lineCount;
    }return 0;
}

void hangman::show_board(int badTries) {
    std::string boards[7] = {
        "  +-----+\n"
        "  |     |\n"
        "        |\n"
        "        |\n"
        "        |\n" 
        "        |\n" 
        "###########\n",
        "  +-----+\n"
        "  |     |\n"
        "  O     |\n"
        "        |\n"
        "        |\n" 
        "        |\n" 
        "###########\n",
        "  +-----+\n"
        "  |     |\n"
        "  O     |\n"
        "  |     |\n"
        "        |\n" 
        "        |\n" 
        "###########\n",
        "  +-----+\n"
        "  |     |\n"
        "  O     |\n"
        " /|     |\n"
        "        |\n" 
        "        |\n" 
        "###########\n",
        "  +-----+\n"
        "  |     |\n"
        "  O     |\n"
        " /|\\    |\n"
        "        |\n" 
        "        |\n" 
        "###########\n",
        "  +-----+\n"
        "  |     |\n"
        "  O     |\n"
        " /|\\    |\n"
        " /      |\n" 
        "        |\n" 
        "###########\n",
        "  +-----+\n"
        "  |     |\n"
        "  O     |\n"
        " /|\\    |\n"
        " / \\    |\n" 
        "        |\n" 
        "###########\n"
    };

    std::cout << boards[badTries] << std::endl;
}

char hangman::getGuess() {
    char guess;

    std::cout << "Guess a letter: ";
    std::cin >> guess;

    return guess;
}

std::string hangman::handleGuess(char guess) {
    
}