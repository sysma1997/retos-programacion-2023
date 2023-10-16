#include <iostream>
#include <string>
#include <map>

using namespace std;

const map<char, string> leet{{'A', "4"}, {'B', "I3"}, {'C', "["}, {'D', ")"}, {'E', "3"}, {'F', "|="}, {'G', "&"}, {'H', "#"}, {'I', "1"}, {'J', ",_|"}, {'K', ">|"}, {'L', "1"}, {'M', "/\\/\\"}, {'N', "^/"}, {'O', "0"}, {'P', "|*"}, {'Q', "(_,)"}, {'R', "I2"}, {'S', "5"}, {'T', "7"}, {'U', "(_)"}, {'V', "\\/"}, {'W', "\\/\\/"}, {'X', "><"}, {'Y', "j"}, {'Z', "2"}, {'1', "L"}, {'2', "R"}, {'3', "E"}, {'4', "A"}, {'5', "S"}, {'6', "b"}, {'7', "T"}, {'8', "B"}, {'9', "g"}, {'0', "o"}};

string leetTranslate(string text);

int main()
{
    cout << leetTranslate("Aquí está un texto de prueba!") << '\n';
    cout << leetTranslate("Sebastian Moreno Acero") << '\n';
    cout << "Digite un texto para traducir: ";
    string textUser{};
    cin >> textUser;
    cout << leetTranslate(textUser);

    return 0;
}

string leetTranslate(string text)
{
    string result{};

    for (int i = 0; i < text.length(); i++)
    {
        text[i] = toupper(text[i]);

        result.append((leet.find(text[i]) != leet.end()) ? leet.at(text[i]) : string(1, text[i]));
    }

    return result;
}