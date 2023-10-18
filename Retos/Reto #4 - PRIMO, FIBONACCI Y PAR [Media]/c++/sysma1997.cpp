#include <iostream>
#include <cstdlib>
#include <math.h>
#include <limits>

using namespace std;

bool checkFibonacci(int number);

int main()
{
    bool isPrime{true}, isFibonacci{false}, isEven{false};

    cout << "Digite un numero: ";
    int number{0};
    cin >> number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Digite un numero entero positivo valido: ";
        cin >> number;
    }
    number = abs(number);

    // check if prime number
    if (number == 0 || number == 1)
        isPrime = false;
    for (int i = 2; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            isPrime = false;
            break;
        }
    }
    // check if fibonacci number
    if (checkFibonacci(number))
        isFibonacci = true;
    // check if even number
    if (number % 2 == 0)
        isEven = true;

    cout << number << " "
         << (isPrime ? "es primo" : "no es primo") << ", "
         << (isFibonacci ? "fibonacci" : "no es fibonacci") << " "
         << (isEven ? "y es par" : "y es impar") << '\n';

    return 0;
}

bool checkFibonacci(int number)
{
    auto isPerfectSquare = [](int x) -> bool
    {
        int square = sqrt(x);
        return square * square == x;
    };

    return isPerfectSquare(5 * number * number + 4) ||
           isPerfectSquare(5 * number * number - 4);
}