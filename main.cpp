#include <iostream>
using namespace std;
int main(){
    // std::string words[7] = {"sports", "music", "play", "chess", "fit", "party", "motion"};
    // std::string chosenWord = words[1];
    // std::string hangman;
    bool GameStarted = false;
    
    std::cout << "Welcome to C++ Hangman Game!" << std::endl;
    std::cout << "Press Any Key To Continue" << std::endl;
    std::cin.get();
    GameStarted = true;
    std::cout << "Game Start!" << std::endl;

    return 0;
}