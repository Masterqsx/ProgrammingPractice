
//File Name:tictactoe.cpp
//Author: Barrett Quan
//Program Description: Tic Tac Toe Game
//Assignment: Final Project
//Last Changed: 8/3/16

#include <iostream>
#include <iomanip>

using namespace std;

//Function Prototype
void init_table(int pTable[][3]);
//Initializes a blank tic tac toe board

void print_table(int pTable [][3]);
//Takes x, y as move inputs. Prints out move to console

bool check_move(int pTable[][3], int pX, int pY);
//Takes x, y ints as input. Returns true when player makes valid move and false when invalid

void player_move(int pTable[][3], int player);
//Either outputs 'X' or 'O' for players move

void cpu_move(int pTable[][3], int player);
//Takes player_move as input and calculates cpu move

bool check_win (int pTable[][3]);
//Checks if player has three in a row to win and returns true if win or cats game

void choose_mode(int& mode);
//Lets user select between single player and multiplayer modes

void multiplayer(int a[][3]);
//Sets up multiplayer rules

void singleplayer(int a[][3]);
//Sets up singleplayer rules (against CPU)

void check_horizontal(int a[][3], int& x, int& y);


int main(){
    char ans;
    int player, mode, x, y;
    int gameboard[3][3];/* = {{'x',' ',' '},{' ','x',' '},{' ',' ','x'}};*/

    do {
        cout << "Let's play Tic Tac Toe!\n" << endl;
        //Print empty grid
        init_table(gameboard);

        check_horizontal(gameboard, x, y);
        choose_mode(mode);

        if (mode == 1)
            //play against cpu
            singleplayer(gameboard);
        else
            //play multiplayer
            multiplayer(gameboard);


        cout << endl;
        cout << "Play again? (y/n): ";
        cin >> ans;
        cout << endl;
    }
    while (ans == 'Y' || ans == 'y');

    return 0;
}

void init_table(int pTable[][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            pTable[i][j] = ' ';
        }
    }
}

bool check_move(int pTable[][3], int pX, int pY)
{
    if((pX >= 0 && pX <= 2)&&(pY >=0 && pY <=2) && pTable[pX][pY] == ' ')
        return true;
    else
        return false;
}

void print_table(int pTable [][3])
{
    for (int i = 0; i < 3; i++)
    {


        for (int j = 0; j < 3;j++)
        {
            cout<<static_cast<char>(pTable[i][j])<<' ';

        }
        cout<<endl<< "- - -"<<endl;
    }

}
void player_move(int pTable[][3], int player)
{
    int x,y;
    //ask user for input
    while(true)
    {
        cout << endl;
        cout<<"Please enter your move (up/down, left/right) using numbers 0 - 2: "<< endl;
        cout<<endl;
        cin >> x >> y;
        cout << endl;

        if (check_move(pTable,x,y))
        {
            pTable[x][y] = player;
            break;
        }
        else
        {
            cout<<"Move is invalid, enter a spot not occupied by player move ie (1, 0)"<<endl;
            continue;
        }
        cout<<endl;
    }
}

void check_horizontal(int a[][3], int& x, int& y)
{
    for (int i = 0; i < 3; i++){
        for (int j; j < 3; j++){
            if (a[i][j] == ' ')
                x = i, y = j;
            cout << x << " " << y << endl;}

    }
}

void cpu_move(int pTable[][3], int player)
{
    int x, y;
    //ask user for input
    while(true)
    {
        cout << endl << "CPU Turn" << endl;
        cout << endl;

        if (check_move(pTable,x,y))
        {
            pTable[x][y] = player;
            break;
        }

        else
        {
            check_horizontal(pTable, x, y);


            //Counter winning moves
            if (((pTable[0][0] == 'X') && (pTable [0][1] == 'X') && (pTable [0][2] == ' ')) || ((pTable[0][0] == 'X') && (pTable [0][1] == ' ') && (pTable [0][2] == 'X')))
            {
                x = 0, y = 2;
            }

            if (((pTable[0][0] == 'X') && (pTable [1][0] == 'X') && (pTable [2][0] == ' ')))
            {
                x = 0, y = 2;
            }

            if (((pTable[0][2] == 'X') && (pTable [1][2] == 'X') && (pTable [2][2] == ' ')))
            {
                x = 2, y = 2;
            }

            if (((pTable[0][1] == 'X') && (pTable [1][1] == 'X') && (pTable [2][1] == ' ')))
            {
                x = 2, y = 1;
            }

            if (((pTable[1][0] == 'X') && (pTable [1][1] == 'X') && (pTable [1][2] == ' ')))
            {
                x = 1, y = 2;
            }

            if (((pTable[2][0] == 'X') && (pTable [2][1] == 'X') && (pTable [2][2] == ' ')))
            {
                x = 2, y = 2;
            }

            if (((pTable[0][0] == 'X') && (pTable [1][1] == 'X') && (pTable [2][2] == ' ')))
            {
                x = 2, y = 2;
            }

            if (((pTable[2][0] == 'X') && (pTable [1][1] == 'X') && (pTable [0][2] == ' ')))
            {
                x = 0, y = 2;
            }


            if (check_move(pTable,x,y))
                break;
            else
                continue;
        }
    }
}


bool check_win (int pTable[][3])
{
    if (((pTable[0][0] == 'X') && (pTable [0][1] == 'X') && (pTable [0][2] == 'X')) || ((pTable[0][0] == 'O') && (pTable [0][1] == 'O') && (pTable [0][2] == 'O')) )
    {
        cout << "You Win!" << endl;
        return true;
    }

    if (((pTable[0][0] == 'X') && (pTable [1][0] == 'X') && (pTable [2][0] == 'X')) || ((pTable[0][0] == 'O') && (pTable [1][0] == 'O') && (pTable [2][0] == 'O')) )
    {
        cout << "You Win!" << endl;
        return true;
    }

    if (((pTable[0][2] == 'X') && (pTable [1][2] == 'X') && (pTable [2][2] == 'X')) || ((pTable[0][2] == 'O') && (pTable [1][2] == 'O') && (pTable [2][2] == 'O')) )
    {
        cout << "You Win!" << endl;
        return true;
    }

    if (((pTable[0][1] == 'X') && (pTable [1][1] == 'X') && (pTable [2][1] == 'X')) || ((pTable[0][1] == 'O') && (pTable [1][1] == 'O') && (pTable [2][1] == 'O')) )
    {
        cout << "You Win!" << endl;
        return true;
    }

    if (((pTable[1][0] == 'X') && (pTable [1][1] == 'X') && (pTable [1][2] == 'X')) || ((pTable[1][0] == 'O') && (pTable [1][1] == 'O') && (pTable [1][2] == 'O')) )
    {
        cout << "You Win!" << endl;
        return true;
    }

    if (((pTable[2][0] == 'X') && (pTable [2][1] == 'X') && (pTable [2][2] == 'X')) || ((pTable[2][0] == 'O') && (pTable [2][1] == 'O') && (pTable [2][2] == 'O')) )
    {
        cout << "You Win!" << endl;
        return true;
    }

    if (((pTable[0][0] == 'X') && (pTable [1][1] == 'X') && (pTable [2][2] == 'X')) || ((pTable[0][0] == 'O') && (pTable [1][1] == 'O') && (pTable [2][2] == 'O')) )
    {
        cout << "You Win!" << endl;
        return true;
    }

    if (((pTable[2][0] == 'X') && (pTable [1][1] == 'X') && (pTable [0][2] == 'X')) || ((pTable[2][0] == 'O') && (pTable [1][1] == 'O') && (pTable [0][2] == 'O')) )
    {
        cout << "You Win!" << endl;
        return true;
    }
    if ((pTable [0][0] != ' ') && (pTable [0][1] != ' ') && (pTable [0][2] != ' ') && (pTable [1][0] != ' ') && (pTable [1][1] != ' ') && (pTable [1][2] != ' ') && (pTable [2][0] != ' ') && (pTable [2][1] != ' ') && (pTable [2][2] != ' '))
    {
        cout << "Cat's game, it's a Tie!" << endl;
        return true;
    }

    else
        return false;
}

void choose_mode(int& mode)
{

    cout << "Which mode would you like to play?\n Enter 1 to start single player mode (against CPU)\n Enter 2 to start multiplayer mode\n";
    cin >> mode;

}



void multiplayer(int a[][3])
{
    do
    {
        //loop for the game; player 1 and 2 takes turns

        //P1
        print_table(a);
        if (check_win(a))
            break;
        player_move(a, 'X');
        check_win (a);

        //P2
        print_table(a);
        if (check_win(a))
            break;
        player_move(a, 'O');
        check_win (a);



    }
    while(!check_win(a));
    cout << endl;
}

void singleplayer(int a[][3])
{
    do
    {
        //loop for the game; player 1 and 2 takes turns

        //P1
        print_table(a);
        if (check_win(a))
            break;
        player_move(a, 'X');
        check_win (a);

        //P2
        print_table(a);
        if (check_win(a))
            break;
        cpu_move(a, 'O');
        check_win (a);



    }
    while(!check_win(a));
    cout << endl;
}
//main.cpp
//Open
//Wang Lijun 
//(wang283808065@gmail.com)Displaying main.cpp.