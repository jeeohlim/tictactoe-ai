///////////////////////////////
//                           //
//      TIC-TAC-TOE A.I.     //
//                           //
//       BY: JEEOH LIM       //           
//                           //
///////////////////////////////

#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <stdlib.h>
#include <ctime>

using namespace std;

//input variables
int player1Input;
int BOTinput;
int difficulty; //1: easy, 2: medium, 3: hard, 4: master (player1 goes second)

//board drawing variable: (0-8)
int gridCounter = 0;

//loop bools
bool player1Turn = true;
bool wonYet = false;

//board drawing bools
bool fullx[9];
bool fullo[9];
bool full[9];

//random turn
int randomTurn;

//functions
void Draw()
{
    if (difficulty == 1)
    {
        cout << "Easy Mode" << endl;
    }
    else if (difficulty == 2)
    {
        cout << "Medium Mode" << endl;
    }
    else if (difficulty == 3)
    {
        cout << "Hard Mode" << endl;
    }
    else if (difficulty == 4)
    {
        cout << "Master Mode" << endl;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) 
        {
            if (fullx[gridCounter] == true)
            {
                cout << "x ";
                gridCounter++;
            }
            else if (fullo[gridCounter] == true)
            {
                cout << "o ";
                gridCounter++;
            }
            else if (gridCounter == player1Input - 1)
            {
                cout << "x ";
                gridCounter++;
            }
            else if (gridCounter == BOTinput - 1)
            {
                cout << "o ";
                gridCounter++;
            }
            else
            {
                cout << ". ";
                gridCounter++;
            }
        }
        cout << endl;
    }
}

int easyBOT() //random moves no matter what, even if it can win
{
    int easyBOT;
    srand (time(NULL));
    easyBOT = rand() % 9 + 1;

    while (full[easyBOT - 1] == true)
    {
        easyBOT = rand() % 9 + 1;
    }

    return easyBOT;
}

int mediumBOT() //if it can win, makes game winning move. Otherwise, random moves
{
    int mediumBOT;

    srand (time(NULL));

    //012
    if (fullo[0] == true && fullo[1] == true && full[2] == false)
    {
        mediumBOT = 3;
    }
    else if (fullo[1] == true && fullo[2] == true && full[0] == false)
    {
        mediumBOT = 1;
    }
    else if (fullo[0] == true && fullo[2] == true && full[1] == false)
    {
        mediumBOT = 2;
    }
    //345
    else if (fullo[3] == true && fullo[4] == true && full[5] == false)
    {
        mediumBOT = 6;
    }
    else if (fullo[3] == true && fullo[5] == true && full[4] == false)
    {
        mediumBOT = 5;
    }
    else if (fullo[4] == true && fullo[5] == true == full[3] == false)
    {
        mediumBOT = 4;
    }
    //678
    else if (fullo[6] == true && fullo[7] == true && full[8] == false)
    {
        mediumBOT = 9;
    }
    else if (fullo[6] == true && fullo[8] == true && full[7] == false)
    {
        mediumBOT = 8;
    }
    else if (fullo[7] == true && fullo[8] == true && full[6] == false)
    {
        mediumBOT = 7;
    }
    //036
    else if (fullo[0] == true && fullo[3] == true && full[6] == false)
    {
        mediumBOT = 7;
    }
    else if (fullo[0] == true && fullo[6] == true && full[3] == false)
    {
        mediumBOT = 4;
    }
    else if (fullo[3] == true && fullo[6] == true && full[0] == false)
    {
        mediumBOT = 1;
    }
    //147
    else if (fullo[1] == true && fullo[4] == true && full[7] == false)
    {
        mediumBOT = 8;
    }
    else if (fullo[1] == true && fullo[7] == true && full[4] == false)
    {
        mediumBOT = 5;
    }
    else if (fullo[4] == true && fullo[7] == true && full[1] == false) 
    {
        mediumBOT = 2;
    }
    //258
    else if (fullo[2] == true && fullo[5] == true && full[8] == false)
    {
        mediumBOT = 9;
    }
    else if (fullo[2] == true && fullo[8] == true && full[5] == false)
    {
        mediumBOT = 6;
    }
    else if (fullo[5] == true && fullo[8] == true && full[2] == false)
    {
        mediumBOT = 3;
    }
    //048
    else if (fullo[0] == true && fullo[4] == true && full[8] == false)
    {
        mediumBOT = 9;
    }
    else if (fullo[0] == true && fullo[8] == true && full[4] == false)
    {
        mediumBOT = 5;
    }
    else if (fullo[4] == true && fullo[8] == true && full[0] == false)
    {
        mediumBOT = 1;
    }
    //246
    else if (fullo[2] == true && fullo[4] == true && full[6] == false)
    {
        mediumBOT = 7;
    }
    else if (fullo[2] == true && fullo[6] == true && full[4] == false)
    {
        mediumBOT = 5;
    }
    else if (fullo[4] == true && fullo[6] == true && full[2] == false)
    {
        mediumBOT = 3;
    }
    else
    {
        mediumBOT = rand() % 9 + 1;

        while (full[mediumBOT - 1] == true)
        {
            mediumBOT = rand() % 9 + 1;
        }
    }

    return mediumBOT;
}

int hardBOT() //same as medium, but tries to stop player 1 from being able to make game winning moves
{
    int hardBOT;

    srand (time(NULL));

    //COMPUTER GAME-WINNING MOVES
    //012
    if (fullo[0] == true && fullo[1] == true && full[2] == false)
    {
        hardBOT = 3;
    }
    else if (fullo[1] == true && fullo[2] == true && full[0] == false)
    {
        hardBOT = 1;
    }
    else if (fullo[0] == true && fullo[2] == true && full[1] == false)
    {
        hardBOT = 2;
    }
    //345
    else if (fullo[3] == true && fullo[4] == true && full[5] == false)
    {
        hardBOT = 6;
    }
    else if (fullo[3] == true && fullo[5] == true && full[4] == false)
    {
        hardBOT = 5;
    }
    else if (fullo[4] == true && fullo[5] == true && full[3] == false)
    {
        hardBOT = 4;
    }
    //678
    else if (fullo[6] == true && fullo[7] == true && full[8] == false)
    {
        hardBOT = 9;
    }
    else if (fullo[6] == true && fullo[8] == true && full[7] == false)
    {
        hardBOT = 8;
    }
    else if (fullo[7] == true && fullo[8] == true && full[6] == false)
    {
        hardBOT = 7;
    }
    //036
    else if (fullo[0] == true && fullo[3] == true && full[5] == false)
    {
        hardBOT = 7;
    }
    else if (fullo[0] == true && fullo[6] == true && full[3] == false)
    {
        hardBOT = 4;
    }
    else if (fullo[3] == true && fullo[6] == true && full[0] == false)
    {
        hardBOT = 1;
    }
    //147
    else if (fullo[1] == true && fullo[4] == true && full[7] == false)
    {
        hardBOT = 8;
    }
    else if (fullo[1] == true && fullo[7] == true && full[4] == false)
    {
        hardBOT = 5;
    }
    else if (fullo[4] == true && fullo[7] == true && full[1] == false)
    {
        hardBOT = 2;
    }
    //258
    else if (fullo[2] == true && fullo[5] == true && full[8] == false)
    {
        hardBOT = 9;
    }
    else if (fullo[2] == true && fullo[8] == true && full[5] == false)
    {
        hardBOT = 6;
    }
    else if (fullo[5] == true && fullo[8] == true && full[2] == false)
    {
        hardBOT = 3;
    }
    //048
    else if (fullo[0] == true && fullo[4] == true && full[8] == false)
    {
        hardBOT = 9;
    }
    else if (fullo[0] == true && fullo[8] == true && full[4] == false)
    {
        hardBOT = 5;
    }
    else if (fullo[4] == true && fullo[8] == true && full[0] == false)
    {
        hardBOT = 1;
    }
    //246
    else if (fullo[2] == true && fullo[4] == true && full[6] == false)
    {
        hardBOT = 7;
    }
    else if (fullo[2] == true && fullo[6] == true && full[4] == false)
    {
        hardBOT = 5;
    }
    else if (fullo[4] == true && fullo[6] == true && full[2] == false)
    {
        hardBOT = 3;
    }

    //STOP PLAYER 1 FROM WINNING
    //012
    else if (fullx[0] == true && fullx[1] == true && full[2] == false)
    {
        hardBOT = 3;
    }
    else if (fullx[1] == true && fullx[2] == true && full[0] == false)
    {
        hardBOT = 1;
    }
    else if (fullx[0] == true && fullx[2] == true && full[1] == false)
    {
        hardBOT = 2;
    }
    //345
    else if (fullx[3] == true && fullx[4] == true && full[5] == false)
    {
        hardBOT = 6;
    }
    else if (fullx[3] == true && fullx[5] == true && full[4] == false)
    {
        hardBOT = 5;
    }
    else if (fullx[4] == true && fullx[5] == true && full[3] == false)
    {
        hardBOT = 4;
    }
    //678
    else if (fullx[6] == true && fullx[7] == true && full[8] == false)
    {
        hardBOT = 9;
    }
    else if (fullx[6] == true && fullx[8] == true && full[7] == false)
    {
        hardBOT = 8;
    }
    else if (fullx[7] == true && fullx[8] == true && full[6] == false)
    {
        hardBOT = 7;
    }
    //036
    else if (fullx[0] == true && fullx[3] == true && full[6] == false)
    {
        hardBOT = 7;
    }
    else if (fullx[0] == true && fullx[6] == true && full[3] == false)
    {
        hardBOT = 4;
    }
    else if (fullx[3] == true && fullx[6] == true && full[0] == false)
    {
        hardBOT = 1;
    }
    //147
    else if (fullx[1] == true && fullx[4] == true && full[7] == false)
    {
        hardBOT = 8;
    }
    else if (fullx[1] == true && fullx[7] == true && full[4] == false)
    {
        hardBOT = 5;
    }
    else if (fullx[4] == true && fullx[7] == true && full[1] == false)
    {
        hardBOT = 2;
    }
    //258
    else if (fullx[2] == true && fullx[5] == true && full[8] == false)
    {
        hardBOT = 9;
    }
    else if (fullx[2] == true && fullx[8] == true && full[5] == false)
    {
        hardBOT = 6;
    }
    else if (fullx[5] == true && fullx[8] == true && full[2] == false)
    {
        hardBOT = 3;
    }
    //048
    else if (fullx[0] == true && fullx[4] == true && full[8] == false)
    {
        hardBOT = 9;
    }
    else if (fullx[0] == true && fullx[8] == true && full[4] == false)
    {
        hardBOT = 5;
    }
    else if (fullx[4] == true && fullx[8] == true && full[0] == false)
    {
        hardBOT = 1;
    }
    //246
    else if (fullx[2] == true && fullx[4] == true && full[6] == false)
    {
        hardBOT = 7;
    }
    else if (fullx[2] == true && fullx[6] == true && full[4] == false)
    {
        hardBOT = 5;
    }
    else if (fullx[4] == true && fullx[6] == true && full[2] == false)
    {
        hardBOT = 3;
    }

    else
    {
        hardBOT = rand() % 9 + 1;

        while (full[hardBOT - 1] == true)
        {
            hardBOT = rand() % 9 + 1;
        }
    }

    return hardBOT;
}

int masterBOT() //goes first, does corner moves to try and trap player 1 into lose-lose situations
{
    int masterBOT;

    srand (time(NULL));

    //COMPUTER GAME-WINNING MOVES
    //012
    if (fullo[0] == true && fullo[1] == true && full[2] == false)
    {
        masterBOT = 3;
    }
    else if (fullo[1] == true && fullo[2] == true && full[0] == false)
    {
        masterBOT = 1;
    }
    else if (fullo[0] == true && fullo[2] == true && full[1] == false)
    {
        masterBOT = 2;
    }
    //345
    else if (fullo[3] == true && fullo[4] == true && full[5] == false)
    {
        masterBOT = 6;
    }
    else if (fullo[3] == true && fullo[5] == true && full[4] == false)
    {
        masterBOT = 5;
    }
    else if (fullo[4] == true && fullo[5] == true && full[3] == false)
    {
        masterBOT = 4;
    }
    //678
    else if (fullo[6] == true && fullo[7] == true && full[8] == false)
    {
        masterBOT = 9;
    }
    else if (fullo[6] == true && fullo[8] == true && full[7] == false)
    {
        masterBOT = 8;
    }
    else if (fullo[7] == true && fullo[8] == true && full[6] == false)
    {
        masterBOT = 7;
    }
    //036
    else if (fullo[0] == true && fullo[3] == true && full[5] == false)
    {
        masterBOT = 7;
    }
    else if (fullo[0] == true && fullo[6] == true && full[3] == false)
    {
        masterBOT = 4;
    }
    else if (fullo[3] == true && fullo[6] == true && full[0] == false)
    {
        masterBOT = 1;
    }
    //147
    else if (fullo[1] == true && fullo[4] == true && full[7] == false)
    {
        masterBOT = 8;
    }
    else if (fullo[1] == true && fullo[7] == true && full[4] == false)
    {
        masterBOT = 5;
    }
    else if (fullo[4] == true && fullo[7] == true && full[1] == false)
    {
        masterBOT = 2;
    }
    //258
    else if (fullo[2] == true && fullo[5] == true && full[8] == false)
    {
        masterBOT = 9;
    }
    else if (fullo[2] == true && fullo[8] == true && full[5] == false)
    {
        masterBOT = 6;
    }
    else if (fullo[5] == true && fullo[8] == true && full[2] == false)
    {
        masterBOT = 3;
    }
    //048
    else if (fullo[0] == true && fullo[4] == true && full[8] == false)
    {
        masterBOT = 9;
    }
    else if (fullo[0] == true && fullo[8] == true && full[4] == false)
    {
        masterBOT = 5;
    }
    else if (fullo[4] == true && fullo[8] == true && full[0] == false)
    {
        masterBOT = 1;
    }
    //246
    else if (fullo[2] == true && fullo[4] == true && full[6] == false)
    {
        masterBOT = 7;
    }
    else if (fullo[2] == true && fullo[6] == true && full[4] == false)
    {
        masterBOT = 5;
    }
    else if (fullo[4] == true && fullo[6] == true && full[2] == false)
    {
        masterBOT = 3;
    }

    //STOP PLAYER 1 FROM WINNING
    //012
    else if (fullx[0] == true && fullx[1] == true && full[2] == false)
    {
        masterBOT = 3;
    }
    else if (fullx[1] == true && fullx[2] == true && full[0] == false)
    {
        masterBOT = 1;
    }
    else if (fullx[0] == true && fullx[2] == true && full[1] == false)
    {
        masterBOT = 2;
    }
    //345
    else if (fullx[3] == true && fullx[4] == true && full[5] == false)
    {
        masterBOT = 6;
    }
    else if (fullx[3] == true && fullx[5] == true && full[4] == false)
    {
        masterBOT = 5;
    }
    else if (fullx[4] == true && fullx[5] == true && full[3] == false)
    {
        masterBOT = 4;
    }
    //678
    else if (fullx[6] == true && fullx[7] == true && full[8] == false)
    {
        masterBOT = 9;
    }
    else if (fullx[6] == true && fullx[8] == true && full[7] == false)
    {
        masterBOT = 8;
    }
    else if (fullx[7] == true && fullx[8] == true && full[6] == false)
    {
        masterBOT = 7;
    }
    //036
    else if (fullx[0] == true && fullx[3] == true && full[6] == false)
    {
        masterBOT = 7;
    }
    else if (fullx[0] == true && fullx[6] == true && full[3] == false)
    {
        masterBOT = 4;
    }
    else if (fullx[3] == true && fullx[6] == true && full[0] == false)
    {
        masterBOT = 1;
    }
    //147
    else if (fullx[1] == true && fullx[4] == true && full[7] == false)
    {
        masterBOT = 8;
    }
    else if (fullx[1] == true && fullx[7] == true && full[4] == false)
    {
        masterBOT = 5;
    }
    else if (fullx[4] == true && fullx[7] == true && full[1] == false)
    {
        masterBOT = 2;
    }
    //258
    else if (fullx[2] == true && fullx[5] == true && full[8] == false)
    {
        masterBOT = 9;
    }
    else if (fullx[2] == true && fullx[8] == true && full[5] == false)
    {
        masterBOT = 6;
    }
    else if (fullx[5] == true && fullx[8] == true && full[2] == false)
    {
        masterBOT = 3;
    }
    //048
    else if (fullx[0] == true && fullx[4] == true && full[8] == false)
    {
        masterBOT = 9;
    }
    else if (fullx[0] == true && fullx[8] == true && full[4] == false)
    {
        masterBOT = 5;
    }
    else if (fullx[4] == true && fullx[8] == true && full[0] == false)
    {
        masterBOT = 1;
    }
    //246
    else if (fullx[2] == true && fullx[4] == true && full[6] == false)
    {
        masterBOT = 7;
    }
    else if (fullx[2] == true && fullx[6] == true && full[4] == false)
    {
        masterBOT = 5;
    }
    else if (fullx[4] == true && fullx[6] == true && full[2] == false)
    {
        masterBOT = 3;
    }
    else if (fullo[0] == true && fullo[8] == false)
    {
        masterBOT = 9;
    }
    else if (fullo[2] == true && fullo[6] == false)
    {
        masterBOT = 7;
    }
    else if (fullo[6] == true && fullo[2] == false)
    {
        masterBOT = 3;
    } 
    else if (fullo[8] == true && fullo[0] == false)
    {
        masterBOT = 1;
    }
    else if (full[0] == false || full[2] == false || full[6] == false || full[8] == false)
    {
        masterBOT = rand() % 4 + 1;
        if (masterBOT == 1)
        {
            masterBOT = 1;
        }
        else if (masterBOT == 2)
        {
            masterBOT = 3;
        }
        else if (masterBOT == 3)
        {
            masterBOT = 7;
        }
        else if (masterBOT == 4)
        {
            masterBOT = 9;
        }

        while (full[masterBOT - 1] == true)
        {
            masterBOT = rand() % 4 + 1;
            if (masterBOT == 1)
            {
                masterBOT = 1;
            }
            else if (masterBOT == 2)
            {
                masterBOT = 3;
            }
            else if (masterBOT == 3)
            {
                masterBOT = 7;
            }
            else if (masterBOT == 4)
            {
                masterBOT = 9;
            }
        }
    }

    return masterBOT;
}

int main()
{
    //initialize arrays
    for (int i = 0; i < 9; i++)
    {
        full[i] = false;
        fullx[i] = false;
        fullo[i] = false;
    }

    system ("clear");
    cout << " ------------------ " << endl;
    cout << "| TIC-TAC-TOE A.I. |" << endl;
    cout << " ------------------ " << endl;
    cout << endl;

    cout << "Input numbers as shown below to play in the grids accordingly:" << endl;
    cout << endl;
    cout << "1 2 3    . . ." << endl;
    cout << "4 5 6 -> . . ." << endl;
    cout << "7 8 9    . . ." << endl;
    cout << endl;

    cout << "Choose a difficulty level: 1 - Easy, 2 - Medium, 3 - Hard, 4 - Master" << endl;
    cin >> difficulty;
    
    //invalid dificulty loop
    while (difficulty != 1 && difficulty != 2 && difficulty != 3 && difficulty != 4)
    {
        cout << "Choose a valid difficulty!" << endl;
        cin >> difficulty;
    }

    srand (time(NULL));
    randomTurn = rand() % 2 + 1;

    if (randomTurn == 1)
    {
        player1Turn = false;
    }
    else if (randomTurn == 2)
    {
        player1Turn = true;
    }

    system("clear");
    Draw();
    if (player1Turn == false)
    {
        cout << "Computer plays first" << endl;
    }
    else if (player1Turn == true)
    {
        cout << "Player 1 plays first" << endl;
    }

    //game loop until win or victory
    while (wonYet == false)
    {
        if (player1Turn == true)
        {
            cin >> player1Input;
            while(full[player1Input - 1] == true)
            {
                cout << "Grid is taken" << endl;
                cin >> player1Input;
            }
            full[player1Input - 1] = true;
            fullx[player1Input - 1] = true;
            player1Turn = false;
            gridCounter = 0;

            system("clear");
            Draw();

            if (fullx[0] == true && fullx[1] == true && fullx[2] == true)
            {
                wonYet = true;
                cout << "Player wins!" << endl;
            }
            else if (fullx[3] == true && fullx[4] == true && fullx[5] == true)
            {
                wonYet = true;
                cout << "Player wins!" << endl;
            }
            else if (fullx[6] == true && fullx[7] == true && fullx[8] == true)
            {
                wonYet = true;
                cout << "Player wins!" << endl;
            }
            else if (fullx[0] == true && fullx[3] == true && fullx[6] == true)
            {
                wonYet = true;
                cout << "Player wins!" << endl;
            }
            else if (fullx[1] == true && fullx[4] == true && fullx[7] == true)
            {
                wonYet = true;
                cout << "Player wins!" << endl;
            }
            else if (fullx[2] == true && fullx[5] == true && fullx[8] == true)
            {
                wonYet = true;
                cout << "Player wins!" << endl;
            }
            else if (fullx[0] == true && fullx[4] == true && fullx[8] == true)
            {
                wonYet = true;
                cout << "Player wins!" << endl;
            }
            else if (fullx[2] == true && fullx[4] == true && fullx[6] == true)
            {
                wonYet = true;
                cout << "Player wins!" << endl;
            }
            if (wonYet == false && full[0] == true && full[1] == true && full[2] == true && full[3] == true && full[4] == true && full[5] == true && full[6] == true && full[7] == true && full[8] == true)
            {
                wonYet = true;
                cout << "Tie!" << endl;
            }
        }
        else if (player1Turn == false)
        {
            if (difficulty == 1)
            {
                BOTinput = easyBOT();
            }
            else if (difficulty == 2)
            {
                BOTinput = mediumBOT();
            }
            else if (difficulty == 3)
            {
                BOTinput = hardBOT();
            }
            else if (difficulty == 4)
            {
                BOTinput = masterBOT();
            }

            full[BOTinput - 1] = true;
            fullo[BOTinput - 1] = true;
            player1Turn = true;
            gridCounter = 0;

            sleep(1);
            system("clear");
            Draw();

            if (fullo[0] == true && fullo[1] == true && fullo[2] == true)
            {
                wonYet = true;
                cout << "Computer wins!" << endl;
            }
            else if (fullo[3] == true && fullo[4] == true && fullo[5] == true)
            {
                wonYet = true;
                cout << "Computer wins!" << endl;
            }
            else if (fullo[6] == true && fullo[7] == true && fullo[8] == true)
            {
                wonYet = true;
                cout << "Computer wins!" << endl;
            }
            else if (fullo[0] == true && fullo[3] == true && fullo[6] == true)
            {
                wonYet = true;
                cout << "Computer wins!" << endl;
            }
            else if (fullo[1] == true && fullo[4] == true && fullo[7] == true)
            {
                wonYet = true;
                cout << "Computer wins!" << endl;
            }
            else if (fullo[2] == true && fullo[5] == true && fullo[8] == true)
            {
                wonYet = true;
                cout << "Computer wins!" << endl;
            }
            else if (fullo[0] == true && fullo[4] == true && fullo[8] == true)
            {
                wonYet = true;
                cout << "Computer wins!" << endl;
            }
            else if (fullo[2] == true && fullo[4] == true && fullo[6] == true)
            {
                wonYet = true;
                cout << "Computer  wins!" << endl;
            }
            if (wonYet == false && full[0] == true && full[1] == true && full[2] == true && full[3] == true && full[4] == true && full[5] == true && full[6] == true && full[7] == true && full[8] == true)
            {
                wonYet = true;
                cout << "Tie!" << endl;
            }
        }
    }

    return 0;
}