#include <iostream>
#include <cstdlib>
#include <ctime> // Include ctime for time(0)

using namespace std;

void playGame(int &guess_count);
void showLastScore(int guess_count);

int main() {
    int sp, guess_count = 0;
    
    while (true) {
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "-------------------- WELCOME TO NUMBER GUESSING GAME --------------------" << endl;
        cout << "-------------------------------------------------------------------------" << endl;
        cout << "Choose one option ---> " << "\n" << endl;
        cout << "1.>>> Play the Game >>>" << endl;
        cout << "2.>>> See the last Game Score >>>" << endl;
        cout << "3.>>> Exit from the Game >>>" << endl;
        cout << "\n" << "Enter Your Option : ";
        cin >> sp;
        
        switch (sp) {
            case 1:
                playGame(guess_count);
                break;
            case 2:
                showLastScore(guess_count);
                break;
            case 3:
                cout << "\n" << "Thanks for Playing the Game...!" << "\n" << endl;
                return 0;
            default:
                cout << "\n" << "Invalid Option Choice... Please Try Again..." << "\n" << endl;
        }
    }
}

void playGame(int &guess_count) {
    int num_range, real_num, guess_num;
    guess_count = 1;
    cout << "\n" << "Let's Start the Game..." << "\n" << endl;
    cout << "-------------------------- NUMBER GUESSING GAME -------------------------" << endl;
    cout << "\n" << "Enter what would you like the range of the numbers to be? : ";
    cin >> num_range;
    srand(time(0));
    real_num = rand() % (num_range + 1);
    
    do {
        cout << "\n" << "Enter your guess number : ";
        cin >> guess_num;
        if (guess_num > real_num) {
            guess_count += 1;
            cout << "The number is lower than your guess...";
        } else if (guess_num < real_num) {
            guess_count += 1;
            cout << "The number is higher than your guess...";
        } else {
            cout << "\n" << "Great.! You guessed the correct number...!!!";
            if (guess_count == 1) {
                cout << "\n" << "You guessed the number in " << guess_count << "st Try.!!!" << "\n" << endl;
            } else {
                cout << "\n" << "You guessed the number in " << guess_count << " Tries...!" << "\n" << endl;
            }
        }
    } while (guess_num != real_num);
}

void showLastScore(int guess_count) {
    if (guess_count == 0) {
        cout << "\n" << "You haven't played the game once yet..." << "\n" << endl;
    } else if (guess_count == 1) {
        cout << "\n" << "In the Last Game, you won the game in " << guess_count << "st Try...!" << "\n" << endl;
    } else {
        cout << "\n" << "In the Last Game, you won the game in " << guess_count << " Tries..." << "\n" << endl;
    }
}
