#include <bits/stdc++.h>
using namespace std;

char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string player1 = " ";
string player2 = " ";
char sign = 'X';
void gridmaker()
{

    cout << "     |" << "     |" << endl;
    cout << "  " << grid[0][0] << "  |" << "  " << grid[0][1] << "  |" << "  " << grid[0][2] << endl;
    cout << "     |" << "     |" << endl;
    cout << "-----------------" << endl;
    cout << "     |" << "     |" << endl;
    cout << "  " << grid[1][0] << "  |" << "  " << grid[1][1] << "  |" << "  " << grid[1][2] << endl;
    cout << "     |" << "     |" << endl;
    cout << "-----------------" << endl;
    cout << "     |" << "     |" << endl;
    cout << "  " << grid[2][0] << "  |" << "  " << grid[2][1] << "  |" << "  " << grid[2][2] << endl;
    cout << "     |" << "     |" << endl;
}

void moves()
{
    char move = '\0';
    cin >> move;
    system("cls"); // system clear cmd
    while (1)
    {
        for (int i = 0; i < 3; i++)
        {
            for (int k = 0; k < 3; k++)
            {
                if ((move == grid[i][k]) && ((move != 'X') && (move != 'O')))
                {
                    grid[i][k] = sign;
                    if (sign == 'X')
                    {
                        sign = 'O';
                    }
                    else
                        sign = 'X';
                    return;
                }
            }
        }
        cout << "invalid move" << endl
             << "enter again:";
        cin >> move;
    }
}

int win_loss()
{
    for (int i = 0; i < 3; i++)
    {
        if ((grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]) || (grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]))
            return 1;
    }
    if ((grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]) || (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]))
        return 1;
    return 0;
}

void who_win(string player)
{
    cout << player << " wins" << endl;
}
int check_draw()
{
    for (int i = 0; i < 3; i++)
    {
        for (int k = 0; k < 3; k++)
        {
            if ((grid[i][k] > '1') && (grid[i][k] < '9'))
            {
                return 1;
            }
        }
    }
    return 0;
}
void grid_intializer()
{
    grid[0][0] = '1';
    grid[0][1] = '2';
    grid[0][2] = '3';
    grid[1][0] = '4';
    grid[1][1] = '5';
    grid[1][2] = '6';
    grid[2][0] = '7';
    grid[2][1] = '8';
    grid[2][2] = '9';
}
bool intial_stn()
{
    int n;
    cout << "\nwant to play another match if yes enter 1 if no enter 0 " << endl;
    for (int h = 0; h < 1; h++)
    {
        cin >> n;
        if (n == 1)
        {
            system("cls"); // system clear cmd
            grid_intializer();
            sign = 'X';
            return true;
        }
        else if (n == 0)
            return false;
        else
        {
            cout << "invalid input" << endl;
            h--;
        }
    }
}

int main()
{
    while (1)
    {
        system("cls");
        cout << "enter the player 1:" << endl;
        cin >> player1;
        cout << "enter the player 2:" << endl;
        cin >> player2;
        cout << player1 << " will play first" << endl
             << player2 << " will play after" << endl;
        while (1)
        {

            gridmaker();
            cout << player1 << " ( X )choose where to make move" << endl;
            moves();
            gridmaker();
            if (win_loss())
            {
                who_win(player1);
                if (intial_stn() == true)
                    break;
                return 0;
            }
            if (!check_draw())
                break;
            cout << player2 << " ( O ) choose where to make move" << endl;
            moves();
            if (win_loss())
            {
                gridmaker();
                who_win(player2);
                if (intial_stn() == true)
                    break;
                return 0;
            }
        }
        if (!check_draw())
        {
            cout << "Draw between " << player1 << " and " << player2 << endl;
            if (intial_stn() == false)
                return 0;
        }
    }
}