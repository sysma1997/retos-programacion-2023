#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum typeOfPlays
{
    TIE,
    POINT_PLAYER_1,
    POINT_PLAYER_2,
    INVALID
};
const map<string, vector<string>> rules{
    {"🗿", {"✂️", "🦎"}},
    {"📄", {"🗿", "🖖"}},
    {"✂️", {"📄", "🦎"}},
    {"🦎", {"📄", "🖖"}},
    {"🖖", {"🗿", "✂️"}}};

void game(vector<vector<string>> rounds);

int main()
{
    game({{"🗿", "📄"}, {"✂️", "🦎"}});
    game({{"🗿", "📄"}, {"✂️", "🦎"}, {"✂️", "✂️"}, {"🖖", "🗿"}});
    game({{"👆", "📄"}, {"🖖", "🦎"}, {"✂️", "🗿"}});
    game({{"✂️", "🦎"}, {"🖖", "🦎"}, {"✂️", "✂️"}});

    return 0;
}

void game(vector<vector<string>> rounds)
{
    auto validate = [](string player1, string player2) -> int
    {
        if (player1 == player2)
            return typeOfPlays::TIE;

        if (rules.find(player1) == rules.end() || rules.find(player2) == rules.end())
            return typeOfPlays::INVALID;

        vector<string> rule = rules.at(player1);
        for (int i = 0; i < rule.size(); i++)
        {
            if (player2 == rule[i])
                return typeOfPlays::POINT_PLAYER_1;
        }

        return typeOfPlays::POINT_PLAYER_2;
    };

    int pointsP1{0}, pointsP2{0};

    for (int i = 0; i < rounds.size(); i++)
    {
        vector<string> round = rounds[i];

        if (round.size() != 2)
            continue;

        int result{validate(round[0], round[1])};
        if (result == typeOfPlays::INVALID || result == typeOfPlays::TIE)
            continue;
        else if (result == typeOfPlays::POINT_PLAYER_1)
            pointsP1++;
        else
            pointsP2++;
    }

    if (pointsP1 == pointsP2)
        cout << "Empate\n";
    else if (pointsP1 > pointsP2)
        cout << "Player 1\n";
    else
        cout << "Player 2\n";
}