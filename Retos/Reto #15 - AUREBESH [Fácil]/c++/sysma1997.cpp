#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<char, string> Aurebest{
    {'A', "Aurek"},
    {'B', "Besh"},
    {'C', "Cresh"},
    {'D', "Dorn"},
    {'E', "Esk"},
    {'F', "Forn"},
    {'G', "Grek"},
    {'H', "Herf"},
    {'I', "Isk"},
    {'J', "Jenth"},
    {'K', "Krill"},
    {'L', "Leth"},
    {'M', "Mern"},
    {'N', "Nern"},
    {'O', "Osk"},
    {'P', "Peth"},
    {'Q', "Qek"},
    {'R', "Resh"},
    {'S', "Senth"},
    {'T', "Trill"},
    {'U', "Usk"},
    {'V', "Vev"},
    {'W', "Wesk"},
    {'X', "Xesh"},
    {'Y', "Yirt"},
    {'Z', "Zerek"},
};

string aurebeshTranslate(string value, bool isAurebesh = false);

int main()
{
    string value{aurebeshTranslate("Sebastian")};

    cout << "Sebastian:\n";
    cout << "In Aurebesh: " << value << '\n';
    cout << "To Aurebesh to normal: " << aurebeshTranslate(value, true) << '\n';

    return 0;
}

string aurebeshTranslate(string value, bool isAurebesh)
{
    string result{""};

    if (!isAurebesh)
    {
        for (int i{0}; i < value.length(); i++)
        {
            value[i] = toupper(value[i]);

            result.append((Aurebest.find(value[i]) != Aurebest.end()) ? Aurebest.at(value[i]) : string(1, value[i]));
        }
    }
    else
    {
        string word{""};
        for (int i{0}; i < value.length(); i++)
        {
            value[i] = toupper(value[i]);
            word.append(string(1, value[i]));

            for (auto &pair : Aurebest)
            {
                string value{pair.second};
                transform(value.begin(), value.end(), value.begin(), ::toupper);

                if (word == value)
                {
                    result.append(string(1, pair.first));
                    word = "";
                    break;
                }
            }
        }
    }

    return result;
}