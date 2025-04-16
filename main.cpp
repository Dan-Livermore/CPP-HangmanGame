#include <iostream>
#include <ctime>

using namespace std;

string words[7] = {"sports", "music", "play", "chess", "fit", "party", "motion"};
string chosenWord;
char hangman[100];
int hangmanLength;
bool GameRunning = false;
bool GameStarted = false;
int turn;
int steps;

void displayHangman()
{
    cout << "" << endl;
    switch (steps)
    {
    case 0:
        cout << " Mistakes: 0 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    case 1:
        cout << " Mistakes: 1 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "║           ║" << endl;
        cout << "║   =====   ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    case 2:
        cout << " Mistakes: 2 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║           ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║   =====   ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    case 3:
        cout << " Mistakes: 3 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║    +--+   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║   =====   ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    case 4:
        cout << " Mistakes: 4 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║    +--+   ║" << endl;
        cout << "║    |  |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║   =====   ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    case 5:
        cout << " Mistakes: 5 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║    +--+   ║" << endl;
        cout << "║    |  |   ║" << endl;
        cout << "║    O  |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║   =====   ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    case 6:
        cout << " Mistakes: 6 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║    +--+   ║" << endl;
        cout << "║    |  |   ║" << endl;
        cout << "║    O  |   ║" << endl;
        cout << "║    |  |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║   =====   ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    case 7:
        cout << " Mistakes: 7 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║    +--+   ║" << endl;
        cout << "║    |  |   ║" << endl;
        cout << "║    O  |   ║" << endl;
        cout << "║   /|  |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║   =====   ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    case 8:
        cout << " Mistakes: 8 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║    +--+   ║" << endl;
        cout << "║    |  |   ║" << endl;
        cout << "║    O  |   ║" << endl;
        cout << "║   /|\\ |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║   =====   ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    case 9:
        cout << " Mistakes: 9 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║    +--+   ║" << endl;
        cout << "║    |  |   ║" << endl;
        cout << "║    O  |   ║" << endl;
        cout << "║   /|\\ |   ║" << endl;
        cout << "║   /   |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║   =====   ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    case 10:
        cout << " Mistakes: 10 " << endl;
        cout << "╔═══════════╗" << endl;
        cout << "║    +--+   ║" << endl;
        cout << "║    |  |   ║" << endl;
        cout << "║    O  |   ║" << endl;
        cout << "║   /|\\ |   ║" << endl;
        cout << "║   / \\ |   ║" << endl;
        cout << "║       |   ║" << endl;
        cout << "║   =====   ║" << endl;
        cout << "╚═══════════╝" << endl;
        break;
    // default:
    //     cout << "Invalid turn" << endl;
    //     break;
    }
}

void updateScore(bool found)
{
    if (string(hangman) == chosenWord)
    {
        cout << "You won!" << endl;
        GameStarted = false;
    }
    if (turn == 10)
    {
        cout << "Game Over!" << endl;
        GameStarted = false;
    };
    if (!GameStarted){
        cout << "The word was: " << chosenWord << endl;
        
        char playAgain;
        do {
            cout << "Play Again? (Y/N): ";
            cin >> playAgain;
            playAgain = toupper(playAgain);
            if (playAgain != 'Y' && playAgain != 'N') {
                cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
            }
        } while (playAgain != 'Y' && playAgain != 'N');
        
        if (playAgain == 'N') {
            cout << "Thank you for playing!" << endl;
            GameRunning = false;        
        }
    };
    cout << "" << endl;
    turn++;
}

void validateGuess(char guess)
{
    bool found = false;
    bool alreadyGuessed = false;
    for (int i = 0; i < hangmanLength; i++)
    {
        // Check if the letter is already guessed
        if (hangman[i] == guess)
        {
            alreadyGuessed = true;
            cout << "Already guessed!" << endl;
            break;
        }
    }
    if (!alreadyGuessed)
    {
        for (int i = 0; i < hangmanLength; i++)
        {
            // If letter is in the word, update hangman. Keep going for duplicate characters
            if (chosenWord[i] == guess)
            {
                hangman[i] = guess;
                found = true;
            }
        }
        if (!found)
        {
            steps++;
        }
    }
    displayHangman();
    cout << "" << endl;
    updateScore(found);
}

void playerGuesses()
{
    cout << "Turn: " << turn + 1 << endl;
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
    srand(time(0));
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
    steps = 0;
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
        }
    }
    return 0;
}