
#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <thread>  
#include <chrono> 

using namespace std;

int  guessTry = 5;
int rangeSize = 10;
int currentplayer = 1;

void delay(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds)); 
}

void consoleClear(){
    #ifdef _WIN32
        system("cls"); 
    #else
        system("clear"); 
    #endif
}

int randomizeRange() {
    srand(static_cast<unsigned int>(time(0))); 
    return rand() % 991;
}

int randomizeNumber() {
    srand(static_cast<unsigned int>(time(0))); 
    return rand() % 10 + randomizeRange();
}


bool numGuess(int secretNumber, int lowRange) {
    int numguess;

    cout << "Player " << currentplayer << ", It is your turn: ";
    cin >> numguess;

    if (numguess == secretNumber) {
        cout << "Player " << currentplayer << " WIIIIIIIIIIIIIIINNNN : " << secretNumber << "!" << endl;
        return true;
    }
    else if (numguess < lowRange || numguess >(lowRange + rangeSize)) {
        cout << "Your guess is out of range " << lowRange << " and " << (lowRange + rangeSize) << "." << endl;
    }
    else {
        cout << "Looser. Try next time more worser" << endl;
    }

    delay(3);
    consoleClear();

    return false;
}

void rulesExplanation(int lowRange, int highRange, int playe1Tries, int player2Tries) {
    cout << "------------------------------------------------" << endl;
    cout << "Welcome to the Number Guessing Game! for 2 players" << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Here's how it works:" << endl;
    cout << "1. I have chosen a secret number between " << lowRange << " and " << highRange << "." << endl;
    cout << "2. Both of you have " << guessTry << " tries to guess the correct number." << endl;
    cout << "3. Don't worry! I'll tell you if your guess is out of range." << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Let's get started! Enter your first guess below." << endl;
    cout << "------------------------------------------------" << endl;
    cout << "Player 1 used " << playe1Tries << " tries out of " << guessTry << endl;
    cout << "Player 2 used " << player2Tries << " tries out of " << guessTry << endl;
    cout << " " << endl;
}

int main()
{
    bool guessed = false;
    int tries[2] = { 0, 0 };
    int secretNumber = randomizeNumber();
    int lowRange = randomizeRange();
    int highRange = lowRange + rangeSize;

    while (tries[0] < guessTry * 2 && !guessed) {
        rulesExplanation(lowRange, highRange, tries[0], tries[1]);

        guessed = numGuess(secretNumber, lowRange);

        if (guessed) {
            break;
        }

        tries[currentplayer - 1]++;
        currentplayer = (currentplayer == 1) ? 2 : 1;
    }
    
    if (!guessed) {
        cout << "Tries are ended, sorry : " << secretNumber << "." << endl;
    }

    return 0;

}
