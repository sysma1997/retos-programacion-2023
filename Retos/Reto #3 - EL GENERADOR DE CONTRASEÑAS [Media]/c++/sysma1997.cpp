#include <iostream>
#include <conio.h>
#include <cstdlib>

using namespace std;

string passwordGenerator(int length,
                         bool withUppercase,
                         bool withNumbers,
                         bool withSymbols);
bool changeConfigYesNo();
void changeConfig(int *length,
                  bool *withUppercase,
                  bool *withNumbers,
                  bool *withSymbols);

int main()
{
    int length{8};
    bool withUppercase{false},
        withNumbers{false},
        withSymbols{false};

    srand((unsigned)time(NULL));

    cout << "Welcome to password generator\n\n";
    bool run{true};
    while (run)
    {
        cout << "Opciones:\n";
        cout << "1 - Generar contraseña\n";
        cout << "2 - Configurar\n";
        cout << "3 - Salir\n\n";
        cout << "Configuracion:\n";
        cout << "Longitud: " << length << '\n';
        cout << "Con mayúsculas: " << ((withUppercase) ? "Si" : "No") << ", ";
        cout << "Con números: " << ((withNumbers) ? "Si" : "No") << ", ";
        cout << "Con símbolos: " << ((withSymbols) ? "Si" : "No") << "\n\n";

        cout << "Digite la opcion: ";
        int option{0};
        cin >> option;
        cout << '\n';

        switch (option)
        {
        case 1:
            cout << "Contraseña generada correctamente:\n";
            cout << passwordGenerator(length, withUppercase,
                                      withNumbers, withSymbols)
                 << '\n';

            getch();
            break;
        case 2:
            changeConfig(&length, &withUppercase, &withNumbers, &withSymbols);
            break;
        case 3:
            run = false;
            break;

        default:
            cout << "Opción no valida.\n";
            getch();
        }

        system("cls");
    }

    return 0;
}

string passwordGenerator(int length,
                         bool withUppercase,
                         bool withNumber,
                         bool withSymbols)
{
    string result{};

    int options{0};
    if (withUppercase)
        options++;
    if (withNumber)
        options++;
    if (withSymbols)
        options++;

    for (int i = 0; i < length; i++)
    {
        int type{(options != 0) ? rand() % (options + 1) : 0};

        char letter{0};
        if (type == 0)
            letter = (rand() % 26) + 97;
        else if (type == 1)
            letter = (rand() % 26) + 65;
        else if (type == 2)
            letter = (rand() % 10) + 48;
        else if (type == 3)
        {
            int typeSymbol{(rand() % 4)};

            if (typeSymbol == 0)
                letter = (rand() % 15) + 33;
            else if (typeSymbol == 1)
                letter = (rand() % 7) + 58;
            else if (typeSymbol == 2)
                letter = (rand() % 6) + 91;
            else if (typeSymbol == 3)
                letter = (rand() % 4) + 123;
        }

        result.append(string(1, letter));
    }

    return result;
}
bool changeConfigYesNo()
{
    system("cls");

    bool run{true};
    while (run)
    {
        cout << "1 - Si\n";
        cout << "2 - No\n";
        int option{0};
        cin >> option;
        cout << '\n';

        if (option == 1)
            return true;
        else if (option == 2)
            return false;
        else
        {
            cout << "Opción no valida\n";
            getch();
        }

        system("cls");
    }

    return false;
}
void changeConfig(int *length,
                  bool *withUppercase,
                  bool *withNumbers,
                  bool *withSymbols)
{
    system("cls");

    bool run{true};
    while (run)
    {
        cout << "Opciones de configuración:\n\n";
        cout << "1 - Cambiar longitud entre 8 y 16: "
             << "Actual " << *length << '\n';
        cout << "2 - Cambiar con o sin letras mayúsculas: "
             << ((*withUppercase) ? "Si" : "No") << '\n';
        cout << "3 - Cambiar con o sin números: "
             << ((*withNumbers) ? "Si" : "No") << '\n';
        cout << "4 - Cambiar con o sin símbolos: "
             << ((*withSymbols) ? "Si" : "No") << '\n';
        cout << "5 - Salir de configuración\n\n";
        cout << "Digite la opcion: ";
        int option{0};
        cin >> option;
        cout << '\n';

        int newLength{8};
        bool result{false};
        switch (option)
        {
        case 1:
            cout << "Digite la nueva longitud: ";
            cin >> newLength;
            cout << '\n';

            if (newLength > 7 && newLength < 17)
                *length = newLength;
            else
            {
                cout << "Longitud fuera del rango\n";
                getch();
            }
            break;
        case 2:
        case 3:
        case 4:
            result = changeConfigYesNo();

            if (option == 2)
                *withUppercase = result;
            else if (option == 3)
                *withNumbers = result;
            else
                *withSymbols = result;

            break;
        case 5:
            run = false;
            break;

        default:
            cout << "Opción no valida\n";
            getch();
        }

        system("cls");
    }
}