#include <iostream>
#include <array>
#define FIELD_SIZE 3

using namespace std;

string field[FIELD_SIZE][FIELD_SIZE];
bool player1Turn, hasNoWinner;
int numberOfMoves;

void init(void);
void printRules(void);
bool doMove(bool, int);
bool hasWinner(int);
string getValueFromField(int);
void clearField(void);
void printPlayField(void);
int main()
{
    printRules();
    playAgain :

    init();

    do {
        start :
        int position = 0;
        if(player1Turn) { cout << "player1(X) make your move:" << endl; }
        else { cout << "player2(O) make your move: " << endl;}

        cin >> position;
        bool succeed = doMove(player1Turn, position);
        if(!succeed) { goto start; }
        printPlayField();

        hasNoWinner = not hasWinner(position);
        if(!hasNoWinner) {
            if(player1Turn) { cout << "player1(X) wins!" << endl; }
            else { cout << "player2(O) wins!" << endl;}
        }

        (player1Turn ? player1Turn = false : player1Turn = true);

        numberOfMoves++;
        if(numberOfMoves == FIELD_SIZE * FIELD_SIZE) { cout << "DRAW!" << endl; break; }

    } while(hasNoWinner);

    cout << "Type an 1 to play again" << endl;
    int input;
    cin >> input;
    if(input == 1) { goto playAgain; }

    return 0;
}

void init(void) {
    player1Turn = true;
    hasNoWinner = true;
    numberOfMoves = 0;

    clearField();
    printPlayField();
}

void printRules(void) {
    cout << "TIC TAC TOE" << endl;
    cout << "2 player game, set an X or O when playing" << endl;
    cout << "Player 1(X) start" << endl;
}

bool doMove(bool isPlayer1, int position) {
    int counter = 1;
    for(int i = 0; i < FIELD_SIZE; i++) {
        for(int j = 0; j < FIELD_SIZE; j++) {

            if(position == counter) {
                if(field[i][j] == "[ ]") {
                    if(isPlayer1) { field[i][j] = "[X]"; }
                    else { field[i][j] = "[O]"; }
                    return true;
                } else {
                    cout << "Field contains a move, try again" << endl;
                    return false;
                }
            }
            counter++;
        }
    }

    cout << "Move outside playfield, try again" << endl;
    return false;
}

bool hasWinner(int position) {
    string valueOnField = getValueFromField(position);
    switch(position) {
        case 1 :
            if((valueOnField == getValueFromField(2) && valueOnField == getValueFromField(3)) || (valueOnField == getValueFromField(5) && valueOnField == getValueFromField(9)) || (valueOnField == getValueFromField(4) && valueOnField == getValueFromField(7))) {
                return true;
            }
            break;
        case 2 :
            if((valueOnField == getValueFromField(1) && valueOnField == getValueFromField(3)) || (valueOnField == getValueFromField(5) && valueOnField == getValueFromField(8))) {
                return true;
            }
            break;
        case 3 :
            if((valueOnField == getValueFromField(1) && valueOnField == getValueFromField(2)) || (valueOnField == getValueFromField(5) && valueOnField == getValueFromField(7)) || (valueOnField == getValueFromField(6) && valueOnField == getValueFromField(9))) {
                return true;
            }
            break;
        case 4 :
            if((valueOnField == getValueFromField(1) && valueOnField == getValueFromField(7)) || (valueOnField == getValueFromField(5) && valueOnField == getValueFromField(6))) {
                return true;
            }
            break;
        case 5 :
            if((valueOnField == getValueFromField(1) && valueOnField == getValueFromField(9)) || (valueOnField == getValueFromField(2) && valueOnField == getValueFromField(8)) || (valueOnField == getValueFromField(3) && valueOnField == getValueFromField(7)) || (valueOnField == getValueFromField(4) && valueOnField == getValueFromField(6))) {
                return true;
            }
            break;
        case 6 :
            if((valueOnField == getValueFromField(3) && valueOnField == getValueFromField(9)) || (valueOnField == getValueFromField(5) && valueOnField == getValueFromField(4))) {
                return true;
            }
            break;
        case 7 :
            if((valueOnField == getValueFromField(1) && valueOnField == getValueFromField(4)) || (valueOnField == getValueFromField(5) && valueOnField == getValueFromField(3)) || (valueOnField == getValueFromField(8) && valueOnField == getValueFromField(9))) {
                return true;
            }
            break;
        case 8 :
            if((valueOnField == getValueFromField(7) && valueOnField == getValueFromField(9)) || (valueOnField == getValueFromField(2) && valueOnField == getValueFromField(5))) {
                return true;
            }
            break;
        case 9 :
            if((valueOnField == getValueFromField(1) && valueOnField == getValueFromField(5)) || (valueOnField == getValueFromField(3) && valueOnField == getValueFromField(6)) || (valueOnField == getValueFromField(7) && valueOnField == getValueFromField(8))) {
                return true;
            }
            break;
    }

    return false;
}

string getValueFromField(int position) {
    int counter = 1;
    for(int i = 0; i < FIELD_SIZE; i++) {
        for(int j = 0; j < FIELD_SIZE; j++) {

            if(position == counter) {
                return field[i][j];
            }
            counter++;
        }
    }
    return "empty";
}

void clearField(void) {
    for(int i = 0; i < FIELD_SIZE; i++) {
        for(int j = 0; j < FIELD_SIZE; j++) {
            field[i][j] = "[ ]";
        }
    }
}

void printPlayField(void) {
    cout << endl;
    for(int i = 0; i < FIELD_SIZE; i++) {
        for(int j = 0; j < FIELD_SIZE; j++) {
            cout << field[i][j];

            if(j == (FIELD_SIZE - 1)) { cout << endl;}
        }
    }
    cout << endl;
}
