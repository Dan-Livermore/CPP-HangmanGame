#include <iostream>

using namespace std;

string words[7] = {"sports", "music", "play", "chess", "fit", "party", "motion"};
string chosenWord;
char hangman[100];
int hangmanLength;
bool GameRunning = false;
bool GameStarted = false;
int turn;
int steps = 0;

void displayHangman()
{
    switch (steps)
    {
    case 1:
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        cout << "" << endl;
        break;
    case 2:
        cout << "" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "=====" << endl;
        break;
    case 3:
        cout << " +--+" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "=====" << endl;
        break;
    case 4:
        cout << " +--+" << endl;
        cout << " |  |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "=====" << endl;
        break;
    case 5:
        cout << " +--+" << endl;
        cout << " |  |" << endl;
        cout << " O  |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "=====" << endl;
        break;
    case 6:
        cout << " +--+" << endl;
        cout << " |  |" << endl;
        cout << " O  |" << endl;
        cout << " |  |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "=====" << endl;
        break;
    case 7:
        cout << " +--+" << endl;
        cout << " |  |" << endl;
        cout << " O  |" << endl;
        cout << "/|  |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "=====" << endl;
        break;
    case 8:
        cout << " +--+" << endl;
        cout << " |  |" << endl;
        cout << " O  |" << endl;
        cout << "/|\\ |" << endl;
        cout << "    |" << endl;
        cout << "    |" << endl;
        cout << "=====" << endl;
        break;
    case 9:
        cout << " +--+" << endl;
        cout << " |  |" << endl;
        cout << " O  |" << endl;
        cout << "/|\\ |" << endl;
        cout << "/   |" << endl;
        cout << "    |" << endl;
        cout << "=====" << endl;
        break;
    case 10:
        cout << " +--+" << endl;
        cout << " |  |" << endl;
        cout << " O  |" << endl;
        cout << "/|\\ |" << endl;
        cout << "/ \\ |" << endl;
        cout << "    |" << endl;
        cout << "=====" << endl;
        turn = 10;
        break;
    default:
        cout << "Invalid turn" << endl;
        break;
    }
}

void updateScore(bool found)
{
    if (hangman == chosenWord)
    {
        cout << "You won!" << endl;
        GameStarted = false;
    }
    if (turn == 10)
    {
        cout << "Game Over!" << endl;
        GameStarted = false;
    };
    cout << "" << endl;
    turn++;
}

void validateGuess(char guess)
{
    bool found = false;
    for (int i = 0; i < hangmanLength; i++)
    {
        // If letter is in the word, update hangman. Keep going for duplicate characters
        if (chosenWord[i] == guess)
        {
            hangman[i] = guess;
            found = true;
        }
    }
    cout << hangman << endl;
    if (!found){
        steps++;
        
    }
    displayHangman();
    updateScore(found);
}

void playerGuesses()
{
    cout << "Hangman: " << hangman << endl;
    char guess;
    cout << "Enter a letter: ";
    cin >> guess;
    // cout << "You guessed: " << guess << endl;
    validateGuess(guess);
}

void prepareHangman(char hangman[])
{
    hangmanLength = chosenWord.length();
    for (int i = 0; i < hangmanLength; i++)
    {
        hangman[i] = '_';
    }
    hangman[hangmanLength] = '\0'; // Limits the char array to length of the word
}

void selectWord(string &chosenWord)
{
    chosenWord = "";
    int randomIndex = rand() % 7;
    chosenWord = words[randomIndex];
    prepareHangman(hangman);
}

void initGame()
{
    // Selects a word and prepares globals for the game
    selectWord(chosenWord);
    GameStarted = true;
    turn = 0;
}

void startup(bool &GameRunning)
{
    cout << "Welcome to C++ Hangman Game!" << endl;
    std::cout << R"(
         __    __       ___       __   __    _______  ___  ___       ___       __   __       _______      ___       ___  ___   _______ 
        |  |  |  |     /   \     |  \ |  |  /  _____||   \/   |     /   \     |  \ |  |     /  _____|    /   \     |   \/   | |   ____|
        |  |__|  |    /  ^  \    |   \|  | |  |  __  |  \  /  |    /  ^  \    |   \|  |    |  |  __     /  ^  \    |  \  /  | |  |__   
        |   __   |   /  /_\  \   |       | |  | |_ | |  |\/|  |   /  /_\  \   |       |    |  | |_ |   /  /_\  \   |  |\/|  | |   __|  
        |  |  |  |  /  _____  \  |  |\   | |  |__| | |  |  |  |  /  _____  \  |  |\   |    |  |__| |  /  _____  \  |  |  |  | |  |____ 
        |__|  |__| /__/     \__\ |__| \__|  \______| |__|  |__| /__/     \__\ |__| \__|     \______| /__/     \__\ |__|  |__| |_______|
                                                                                                                                            
          )" << std::endl;

    cout << "Press Enter To Continue" << endl;
    cin.ignore();
    GameRunning = true;
    cout << "Game Start!" << endl;
}

int main()
{
    startup(GameRunning);
    while (GameRunning)
    {
        initGame();
        while (GameStarted)
        {
            playerGuesses();
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