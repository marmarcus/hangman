#include "hangman.h"

void hangman::start() {
    //variables
    int mode;

    //intro
    std::cout << "\t~~Welcome to Hangman!~~\n" << std::endl;
    std::cout << "Select How You Want To Play:" << std::endl;
    std::cout << "1. Random Word\n2. Custom Word\n" << std::endl;

    std::cin >> mode;
    switch(mode){
        case 1: // Random Word
            randWord();
            break;
        case 2: // Custom Word
            std::cout << "Enter a custom word: ";
            std::cin >> answer;
            break;
        default:
            std::cout << "Invalid Option\nProgram Terminating.." << std::endl;
    }

    for(int i = 0; i < answer.size(); i++){ // make every letter lowercase
        answer[i] = tolower(answer[i]);
    }

    std::cout << "\nStarting Game..\n" << std::endl;

    initialize(); // sets up the placeholders in the "guess" variable

    while(!win && !lose){
        showBoard();

        std::cout << "There are " << answer.size() << " letters in the word.\n" << std::endl;
        std::cout << "You have " << lives << " guesses left!" << std::endl;
        std::cout << "Your current guess has: " << guess << "\n" << std::endl;

        getGuess();
        handleGuess();

        if((guess == answer) && (lives > 0)) {
            win = true;
        }
        else if(lives == 0){
            lose = true;
        }
    }

    if(lose){
        showBoard(); 
        std::cout << "You lose! :(\nThe correct word was " << answer <<  ".\nBetter luck next time.." << std::endl;
    }

    if(win){
        std::cout << "Congrats, you won!\nYour word was " << guess << std::endl;
    }
}

//---------------------------------------------------------------------------------------------

void hangman::randWord() {
    std::ifstream wordFile("words.txt");
    int line;

    srand(time(0));
    line = rand() % numWords();

    while(wordFile.is_open()){
        for(int i = 0; i < line; i++){
            std::getline(wordFile, answer);
        }
        wordFile.close();
    }
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

void hangman::initialize() {
    for(int i = 0; i < answer.size(); i++){
        guess.push_back('-');
    }
}

void hangman::showBoard() {
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

    std::cout << "\n" << boards[6 - lives] << std::endl;
}

void hangman::getGuess() {
    std::cout << "Guess a letter: ";
    std::cin >> letter;
    std::cout << std::endl;
}

void hangman::handleGuess() {
    bool flag = false;

    for(int i = 0; i < answer.size(); i++){
        if(tolower(letter) == answer[i]){
            guess[i] = tolower(letter);
            flag = true;
        }
    }

    if(!flag){
        lives--;
    }
}