#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string text, char character);

int main()
{
    string url{"https://retosdeprogramacion.com?yr=2023&challenge=0&parmetro5=otracosa&parametro7=2345"};

    vector<string> urlParams{split(url, '?')};
    vector<string> params{split(urlParams[1], '&')};
    vector<string> values{};

    for (string param : params)
    {
        vector<string> keyValue{split(param, '=')};
        values.push_back(keyValue[1]);
    }

    cout << "Los parametros serian: ";
    for (int i = 0; i < values.size(); i++)
    {
        string value{values[i]};

        if (i == values.size() - 1)
        {
            cout << value << '\n';
            continue;
        }

        cout << value << ", ";
    }

    return 0;
}

vector<string> split(string text, char character)
{
    vector<string> result{};

    string buffer{};
    for (int i = 0; i < text.length(); i++)
    {
        char _character = text[i];

        if (_character == character)
        {
            result.push_back(buffer);
            buffer = "";
            continue;
        }

        buffer += _character;

        if (i == text.length() - 1)
            result.push_back(buffer);
    }

    return result;
}