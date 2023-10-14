#include <iostream>
#include <string>

using namespace std;

string leetAlphabet(char letter);
string leet(string text);

int main()
{
    cout << leet("Sebastian") << '\n';

    return 0;
}

string leetAlphabet(char letter)
{
    switch (letter)
    {
    case 'A':
        return "4";
    case 'B':
        return "I3";
    case 'C':
        return "[";
    case 'D':
        return ")";
    case 'E':
        return "3";
    case 'F':
        return "|=";
    case 'G':
        return "&";
    case 'H':
        return "#";
    case 'I':
        return "1";
    case 'J':
        return ",_|";
    case 'K':
        return ">|";
    case 'L':
        return "1";
    case 'M':
        return "/\\/\\";
    case 'N':
        return "^/";
    case 'O':
        return "0";
    case 'P':
        return "|*";
    case 'Q':
        return "(_,)";
    case 'R':
        return "I2";
    case 'S':
        return "5";
    case 'T':
        return "7";
    case 'U':
        return "(_)";
    case 'V':
        return "\\/";
    case 'W':
        return "\\/\\/";
    case 'X':
        return "><";
    case 'Y':
        return "j";
    case 'Z':
        return "2";

    default:
        return "";
    }
}
string leet(string text)
{
    string result{};

    for (int i = 0; i < text.length(); i++)
    {
        text[i] = toupper(text[i]);

        result.append(leetAlphabet(text[i]));
    }

    return result;
}