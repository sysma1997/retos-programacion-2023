#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool heterograma(string texto);
bool isograma(string texto);
bool pangrama(string texto);

string setBool(bool value)
{
    return value ? "Si" : "No";
}

int main()
{
    cout << "Texto: yuxtaponer\n";
    cout << "Es heterograma: " << setBool(heterograma("yuxtaponer")) << '\n';
    cout << "Texto: yuxtaponerr\n";
    cout << "Es heterograma: " << setBool(heterograma("yuxtaponerr")) << "\n\n";

    cout << "Texto: UNCOPYRIGHTABLE\n";
    cout << "Es isograma: " << setBool(isograma("UNCOPYRIGHTABLE")) << '\n';
    cout << "Texto: acondicionar\n";
    cout << "Es isograma: " << setBool(isograma("acondicionar")) << "\n\n";

    string textPangrama{"Benjamin pidio una bebida de kiwi y fresa. Noe, sin verguenza, la mas exquisita champana del menu"};
    cout << "Texto: " << textPangrama << '\n';
    cout << "Es pangrama: " << setBool(pangrama(textPangrama)) << '\n';
    string alphabet = "abcdefghijklmnopqrstuvwxy";
    cout << "Texto: " << alphabet << '\n';
    cout << "Es panagrama: " << setBool(pangrama(alphabet)) << '\n';

    return 0;
}

/**
 * del griego héteros, 'diferente' y gramma, 'letra'.
 * Es una palabra o frase que no contiene ninguna letra repetida.
 */
bool heterograma(string text)
{
    vector<char> letters{};

    for (char letter : text)
    {
        letter = toupper(letter);

        if (letters.size() == 0)
        {
            letters.push_back(letter);
            continue;
        }

        for (int i = 0; i < letters.size(); i++)
        {
            if (letter == letters[i])
                return false;
        }
        letters.push_back(letter);
    }

    return true;
}
/**
 * del griego isos, 'igual' y gramma, 'letra'.
 * Es una palabra o frase en la que cada letra aparece el
 * mismo número de veces.
 */
bool isograma(string text)
{
    map<char, int> letters{};

    for (char letter : text)
    {
        letter = toupper(letter);

        if (letters.size() == 0)
        {
            letters[letter] = 1;
            continue;
        }

        bool letterExists = false;
        for (auto &[key, value] : letters)
        {
            if (letter == key)
            {
                letters[key] += 1;
                letterExists = true;
                break;
            }
        }

        if (!letterExists)
            letters[letter] = 1;
    }

    int num{0};
    bool isFirst{true};
    for (auto &[key, value] : letters)
    {
        if (isFirst)
        {
            num = value;
            isFirst = false;
            continue;
        }

        if (num != value)
            return false;
    }

    return true;
}
/**
 * del griego pan, 'todo' y gramma, 'letra'.
 * Es una frase en la que aparecen todas las letras del abecedario.
 */
bool pangrama(string text)
{
    int maxLetters{26};
    vector<char> letters{};

    for (char letter : text)
    {
        letter = toupper(letter);

        if ((int)letter < 65 || (int)letter > 90)
            continue;

        if (letters.size() == 0)
        {
            letters.push_back(letter);
            continue;
        }

        bool exists{false};
        for (int i = 0; i < letters.size(); i++)
        {
            if (letter == letters[i])
            {
                exists = true;
                break;
            }
        }

        if (!exists)
            letters.push_back(letter);
    }

    if (letters.size() == maxLetters)
        return true;

    return false;
}