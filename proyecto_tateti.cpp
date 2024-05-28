#include <iostream>
using namespace std;

char board [3][3] =
    {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'}
    };

char play();
void printBoard();
void resetBoard();
void move(char player, int full[9]);
bool checkWin(char player);
bool checkDraw();

int main()
{
    int replay;
    char player;
    int Xwin = 0;
    int Owin = 0;
    int draws = 0;

    cout << "\n₊˚⊹⋆˙˚˖ ࣪☆.°*₊˚⊹⋆˙˚˖ ࣪\n";
    cout << "¡Bienvenido al juego!\n";
    cout << "⋆˙˚˖ ࣪☆.°*₊˚⊹⋆˙˚˖ ࣪☆.°*\n\n";
    
    do
    {
        player = play();
        if (player == 'E')
        {
            draws++;
        }
        else if (player == 'X')
        {
            Xwin++;
        } 
        else
        {
            Owin++;
        }
        cout << "───────────── ⋆⋅☆⋅⋆ ────────────\n";
        cout << "Puntajes:\n";
        cout << "X = " << Xwin << "\n";
        cout << "O = " << Owin << "\n";
        cout << "Empates = " << draws << "\n";
        cout << "───────────── ⋆⋅☆⋅⋆ ────────────\n";
        do
        {
            cout << "¿Quieres jugar de nuevo?\n";
            cout << "[1] Sí\n";
            cout << "[2] No\n";
            cin >> replay;
        } while (replay < 1 || replay > 2);
        resetBoard();
    } while (replay == 1);

    cout << "───────────── ⋆⋅☆⋅⋆ ────────────\n";
    cout << "Partidas totales:\n";
    cout << "Has jugado " << draws + Xwin + Owin << " partidas.\n\n";
    cout << "⋆˙˚˖ ࣪☆.°*₊˚⊹˖ ࣪☆.°⊹*\n";
    cout << "¡Gracias por jugar!\n";
    cout << "⋆˙˚˖ ࣪☆.°*˚₊˚°*˙˚˖ ࣪☆.\n\n";

    return 0;
}

char play()
{
    bool endgame = false;
    bool draw = false;
    int cont = 0;
    int full[9] = {};
    char player;

    printBoard();

    do
    {
        cont = cont + 1;
        
        if (cont % 2 == 0) 
            player = 'X';
        else
            player = 'O';
        
        move(player, full);
        printBoard();
        endgame = checkWin(player);
        draw = checkDraw();

    } while (endgame == false && draw == false);

    if (endgame == true)
    {
        cout << "El ganador es " << player << "\n";
    } 
    else
    {
        cout << "Es un empate.\n";
        player = 'E';
    }

    return player;
}

void printBoard()
{    
    cout << "-------------------\n";
    cout << "|  " << board [0][0]<< "  |  "<<board[0][1]<<"  |  "<<board[0][2]<<"  |\n";
    cout << "|-----|-----|-----|\n";
    cout << "|  " << board [1][0]<< "  |  "<<board[1][1]<<"  |  "<<board[1][2]<<"  |\n";
    cout << "|-----|-----|-----|\n";
    cout << "|  " << board [2][0]<< "  |  "<<board[2][1]<<"  |  "<<board[2][2]<<"  |\n";
    cout << "-------------------\n\n";

}

void move(char player, int full[9])
{
    int casillero;

    do {
        cout << "Es el turno de " << player << "...\n";
        cout << "Ingrese a que casillero se quiere mover (1-9): ";
        cin >> casillero;
        cout << "\n";

        if (full[casillero] == casillero)
        {
            cout << "⚠︎ El lugar está ocupado. ¡Elija otra posición! ⚠︎\n\n";
            casillero = 0;
        } 
        else 
        {
            full[casillero] = casillero;
        }
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
    for (int i = 0; i < 3; i++) 
    {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return true;
    }
    
    if ((board[0][0] == player && board[1][1] == player && board [2][2] == player) || 
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
    {
        return true;
    }

    return false;
}

bool checkDraw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((board[i][j] != 'O') && (board[i][j] != 'X'))
            return false;
        }
    }
    return true;
}

void resetBoard()
{
    board [0][0] = '1';
    board [0][1] = '2';
    board [0][2] = '3';
    board [1][0] = '4';
    board [1][1] = '5';
    board [1][2] = '6';
    board [2][0] = '7';
    board [2][1] = '8';
    board [2][2] = '9';
}