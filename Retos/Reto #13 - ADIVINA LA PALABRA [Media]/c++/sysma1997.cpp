#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <vector>

using namespace std;

const vector<string> words{"level",
                           "gamer",
                           "Hangman",
                           "sysma1997",
                           "mouredev",
                           "software",
                           "hardware",
                           "google",
                           "apple",
                           "microsoft"};

int main()
{
    srand((unsigned)time(NULL));

    int index{rand() % static_cast<int>(words.size())};
    string word{words[index]};

    int wordLenght{static_cast<int>(word.length())};
    int percent60{static_cast<int>(wordLenght * 0.6)};
    int diff{wordLenght - percent60};
    vector<char> hiddeLetters{};
    for (int i{0}; i < diff; i++)
    {
        index = rand() % wordLenght;
        if (hiddeLetters.size() == 0)
        {
            hiddeLetters.push_back(word[index]);
            continue;
        }
        bool exist{false};
        for (int j{0}; j < hiddeLetters.size(); j++)
        {
            if (hiddeLetters[j] == word[index])
            {
                exist = true;
                break;
            }
        }
        if (exist)
        {
            i--;
            continue;
        }

        hiddeLetters.push_back(word[index]);
    }

    bool isWin{false};
    int tries{5};
    vector<char> letters{};
    while (true)
    {
        cout << "Word: ";
        for (int i{0}; i < word.length(); i++)
        {
            bool exist{false};
            for (int j{0}; j < hiddeLetters.size(); j++)
            {
                if (hiddeLetters[j] == word[i])
                {
                    exist = true;
                    break;
                }
            }
            if (letters.size() > 0)
                for (int j{0}; j < letters.size(); j++)
                {
                    if (letters[j] == word[i])
                    {
                        exist = false;
                        break;
                    }
                }

            if (exist)
                cout << "_";
            else
                cout << word[i];
        }
        cout << '\n';
        cout << "tries: " << tries << '\n';

        cout << "Digit letter or word: ";
        string letter{""};
        cin >> letter;
        cout << '\n';

        if (letter.length() == 0)
        {
            cout << "Required letter or word\n";
            getch();
            system("cls");
        }
        else if (letter.length() > 1)
        {
            if (letter == word)
            {
                system("cls");
                cout << "You win, the word is " << word << '\n';
                getch();

                return 0;
            }

            tries--;
            cout << "Not is word\n";
            getch();
            system("cls");
        }
        else
        {
            char cLetter{letter[0]};
            bool exist{false};
            for (int i{0}; i < hiddeLetters.size(); i++)
            {
                if (cLetter == hiddeLetters[i])
                {
                    exist = true;
                    break;
                }
            }

            if (letters.size() > 0)
            {
                for (int i{0}; i < letters.size(); i++)
                {
                    if (cLetter == letters[i])
                    {
                        exist = false;
                        break;
                    }
                }
            }
            if (exist)
            {
                letters.push_back(cLetter);

                if (letters.size() == hiddeLetters.size())
                {
                    system("cls");
                    cout << "You win, the word is " << word << '\n';
                    getch();

                    return 0;
                }
            }
            else
            {
                tries--;

                if (tries <= 0)
                {
                    system("cls");
                    cout << "You lose, the word is " << word << '\n';
                    getch();

                    return 0;
                }

                system("cls");
            }
        }
    }

    return 0;
}