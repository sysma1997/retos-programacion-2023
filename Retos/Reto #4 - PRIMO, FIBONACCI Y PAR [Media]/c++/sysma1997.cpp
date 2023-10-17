#include <iostream>
#include <cstdlib>
#include <limits>

using namespace std;

int main()
{
    bool isPrime{false}, isFibonacci{false}, isEven{false};

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

    return 0;
}