#include <iostream>
#include <cmath>
using namespace std;
void add(long double a, long double b)
{
    cout << (long double)(a + b);
}
void multiply(long double a, long double b)
{
    cout << (long double)(a * b);
}
void divide(long double a, long double b)
{
    cout << (long double)(a / b);
}
void subtract(long double a, long double b)
{
    cout << (long double)(a - b);
}
int main()
{
    long double number1;
    long double number2;
    int choice;
    cout<<"\n*** SIMPLE CALCULATOR ***\n";
    cout << "enter number 1:" << endl;
    cin >> number1;
    cout << "enter number 2:" << endl;
    cin >> number2;
    cout << "<-OPERATIONS->" << endl
         << "1. To add number 1 and number 2" << endl
         << "2. To multiply number 1 and number 2" << endl
         << "3. To divide number 1 by number 2" << endl
         << "4. To subtract number 2 from number 1" << endl;

    while (1)
    {
        cout << "Enter your choice" << endl;
        cin >> choice;
        if ((choice >= 1) && (choice <= 4))
            break;
        else
            cout << "invalid input" << endl;
    }
    switch (choice)
    {
    case 1:
        cout << number1 << " + " << number2 << " = ";
        add(number1, number2);
        break;
    case 2:
        cout << number1 << " * " << number2 << " = ";
        multiply(number1, number2);
        break;
    case 3:
        cout << number1 << " / " << number2 << " = ";
        divide(number1, number2);
        break;
    case 4:
        cout << number1 << " - " << number2 << " = ";
        subtract(number1, number2);
        break;
    }
}
