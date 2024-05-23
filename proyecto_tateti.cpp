#include <iostream>
using namespace std;

char board [3][3] =
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

void play();
void printBoard();
void move(char player);
bool checkWin(char player);

int main()
{
    play();
    return 0;
}

void play()
{
    bool endgame = false;
    int cont = 0;
    char player;

    printBoard();

    do
    {
        cont = cont + 1;
        if (cont % 2 == 0) 
            player = 'X';
        else
            player = 'O';
        
        move(player);
        printBoard();
        endgame = checkWin(player);
        
    } while (endgame == false);

    cout << "The winner is " << player;
}

void printBoard()
{    
    cout << "-------------------\n";
    cout << "|  " << board [0][0]<< "  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  |\n";
    cout << "|-----|-----|-----|\n";
    cout << "|  " << board [1][0]<< "  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  |\n";
    cout << "|-----|-----|-----|\n";
    cout << "|  " << board [2][0]<< "  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  |\n";
    cout << "-------------------\n";

}

void move(char player)
{
    int casillero;
    do {
        cout << "Ingrese a que casillero se quiere mover (1-9): ";
        cin >> casillero;
    } while (casillero < 1 || casillero > 9);
    

    switch (casillero)
    {
        case 1:
            board[0][0] = player;
            break;
        case 2:
            board[0][1] = player;
            break;
        case 3:
            board[0][2] = player;
            break;
        case 4:
            board[1][0] = player;
            break;
        case 5:
            board[1][1] = player;
            break;
        case 6:
            board[1][2] = player;
            break;
        case 7:
            board[2][0] = player;
            break;
        case 8:
            board[2][1] = player;
            break;
        case 9:
            board[2][2] = player;
            break;
    }
}

bool checkWin(char player)
{
    if ((board[0][0] == player && board[1][1] == player && board [2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player) ||
        (board[0][0] == player && board[0][1] == player && board [0][2] == player))
    {
        return true;
    }
    return false;
}