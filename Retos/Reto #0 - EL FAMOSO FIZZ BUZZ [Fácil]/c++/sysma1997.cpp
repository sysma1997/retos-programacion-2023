#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 100; i++)
    {
        int number = i + 1;

        if (number % 3 == 0 && number % 5 == 0)
            cout << "fizzbuzz";
        else if (number % 3 == 0)
            cout << "fizz";
        else if (number % 5 == 0)
            cout << "buzz";
        else
            cout << number;

        cout << '\n';
    }

    return 0;
}