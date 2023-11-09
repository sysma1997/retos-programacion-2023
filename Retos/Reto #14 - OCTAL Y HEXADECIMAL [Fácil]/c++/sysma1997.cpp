#include <iostream>

using namespace std;

void parseOctalHexa(int value);

int main()
{
    parseOctalHexa(10);
    parseOctalHexa(1234);

    return 0;
}

void parseOctalHexa(int value)
{
    auto parseOctal = [](int value) -> long
    {
        int remainer{0};
        long octal{0}, i{1};

        while (value != 0)
        {
            remainer = value % 8;
            value /= 8;
            octal += (remainer * i);
            i *= 10;
        }

        return octal;
    };
    auto parseHexa = [](int value) -> string
    {
        string hexa{""};

        while (value != 0)
        {
            int remainer{0};
            remainer = value % 16;

            char ch;
            if (remainer < 10)
                ch = remainer + 48;
            else
                ch = remainer + 55;

            hexa += ch;
            value /= 16;
        }

        int i{0}, j = hexa.size() - 1;
        while (i <= j)
        {
            swap(hexa[i], hexa[j]);
            i++;
            j--;
        }

        return hexa;
    };

    cout << "The " << value << " in Octal (" << parseOctal(value)
         << ") and Hexa (" << parseHexa(value) << ")\n";
}