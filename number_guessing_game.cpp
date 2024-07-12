#include <bits/stdc++.h>
using namespace std;
int main()
{
    system("cls");
    cout<<"\n\nNUMBER GUESSING GAME\n\n";
    int upper,lower;
    cout<<"Enter the upper limit of random number"<<endl;
    cin>>upper;
    cout<<"Enter the lower limit of random number"<<endl;
    cin>>lower;
    cout << "\nI have generated a random number between " << lower << " and " << upper << "." << endl;
    srand(time(0));
    int number = rand() % (upper - lower + 1) + lower;
    while (1)
    {   int guess_number=0;
        cout << "Enter your guess" << endl;
        cin >> guess_number;
        if (guess_number > number)
            cout << "Too high! Try again." << endl;
        else if (guess_number < number)
            cout << "Too low! Try again." << endl;
        else if (guess_number == number)
        {
            cout << "Congratulations! You guessed the correct number: " << guess_number << endl;
            break;
        }
    }
}