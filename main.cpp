#include <iostream>

using namespace std;

string words[7] = {"sports", "music", "play", "chess", "fit", "party", "motion"};
string chosenWord;
char hangman[100];
int hangmanLength;
bool GameRunning = false;
bool GameStarted = false;
int turn;

void prepareHangman(char hangman[]){
    int hangmanLength = chosenWord.length();
    for (int i = 0; i < hangmanLength; i++) {
        hangman[i] = '_';
    }
    hangman[hangmanLength] = '\0'; // Limits the char array to length of the word

    cout << "Word length: " << hangmanLength << endl;
    cout << "Word selected: " << hangman << endl;
    cout << "Word selected: " << chosenWord << endl;
}

void selectWord(string &chosenWord){
    chosenWord = "";
    int randomIndex = rand() % 7;
    chosenWord = words[randomIndex];
    prepareHangman(hangman);
}

void initGame(){
    // Selects a word and prepares globals for the game
    selectWord(chosenWord);
    GameStarted = true;
    turn = 0;
}

void startup(bool &GameRunning){
    cout << "Welcome to C++ Hangman Game!" << endl;
    cout << "Press Enter To Continue" << endl;
    cin.ignore();
    GameRunning = true;
    cout << "Game Start!" << endl;
}

int main(){
    startup(GameRunning);
    while (GameRunning){
        initGame();
        while (GameStarted){
            // Player Guesses
            // Check if letter is in the word
            // If letter is in the word, replace the underscore with the letter
            // If letter is not in the word, increment the turn
            // If turn is 10*, game over
            // If all letters are guessed, game won
            // If game is won or lost, ask if player wants to play again
            
        }
    }
    return 0;
}