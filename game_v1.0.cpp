// *******************************************************************************
// Course: TCP1101 PROGRAMMING FUNDAMENTALS 
// Year: Trimester 1, 2022/23 (T2215) 
// Lab: TT3L 
// Names: AHMAD AIMAN NAZHAN BIN MOHD AZHAR | MUHAMMAD HAZIM NAQIUDDIN BIN HARMAN
// IDs: 1221303604 | 1221303684
// Emails: 1221303604@STUDENT.MMU.EDU.MY | 1221303684@STUDENT.MMU.EDU.MY
// Phones: 0179735739 | 0149159172
// *******************************************************************************

#include <iostream>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string>
using namespace std;

void resetBoard()
{
    // for (int i = 0; i < 9; i++)
    //{
    //     for (int j = 0; j < 9; j++)
    //     {
    //         board[i][j] = ' ';
    //     }
    // }
}
void printBoard()
{
    int rows = 9;
    int cols = 9;

    srand(time(0));

    int arr[rows][cols];

    int i;
    int j;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = 1 + (rand() % 9);
            arr[4][4] = 0;
        }

    cout << "The rows of 2d array are: " << rows << " and columns are: " << cols << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << arr[i][j] << "|";
        cout << endl;
    }
    cout << "\n";
    cout << "\n0 = ALIEN";
    cout << "\n1 = ZOMBIE";
    cout << "\n2-4 = POWER-UPS";
    cout << "\n5-9 = BLANKS";
}
void alienMove()
{
}
int checkNoZombie()
{
    return 0;
}
void zombieMove()
{
}
char checkWinner()
{
    return 0;
}
void printWinner(char winner)
{
    // if (winner == ALIEN)
    //  {
    //      cout << "YOU WIN!";
    //  }
    // else if (winner == ZOMBIE)
    //{
    //     cout << "YOU LOSE!";
    // }
    // else
    //{
    //    cout << "IT'S A TIE!";
    // }
}
void menu()
{
    int choice;
    do
    {
        cout << "\n================= MAIN MENU =================";
        cout << "\n\t0. Play\n\t1. Settings\n\t2. credits\n\t3. exit\n";
        cout << "=============================================";
        cout << "\n";
        cout << "Enter the number :";
        cin >> choice;
        switch (choice)
        {
        case 0:
            system("cls");
            cout << "You are playing the game\n";
            printBoard();
            break;
        case 1:
            system("cls");
            cout << "Your in the settings\n";
            cout << "\n";
            break;
        case 2:
            system("cls");
            cout << "by Nazhan & Hazim \n";
            break;
        case 3:
            system("cls");
            cout << "Ok Bye\n";
        }

    } while (choice != 3);
}

int main()
{
    menu();
}
