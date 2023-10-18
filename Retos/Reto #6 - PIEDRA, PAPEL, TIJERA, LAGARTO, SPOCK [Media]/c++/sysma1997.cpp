#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum typeOfPlays
{
    TIE,
    POINT_PLAYER_1,
    POINT_PLAYER_2,
    INVALID
};
void game(vector<vector<string>> rounds);

int main()
{
    game({{"🗿", "📄"}, {"✂️", "🦎"}});                           // empate
    game({{"🗿", "📄"}, {"✂️", "🦎"}, {"✂️", "✂️"}, {"🖖", "🗿"}}); // player 1
    game({{"👆", "📄"}, {"🖖", "🦎"}, {"✂️", "🗿"}});             // player 2

    return 0;
}

void game(vector<vector<string>> rounds)
{
    auto validate = [](string player1, string player2) -> int
    {
        if (player1 == player2)
            return typeOfPlays::TIE;

        if (player1 == "🗿")
        {
            if (player2 == "✂️" || player2 == "🦎")
                return typeOfPlays::POINT_PLAYER_1;
            else if (player2 == "📄" || player2 == "🖖")
                return typeOfPlays::POINT_PLAYER_2;
        }
        else if (player1 == "📄")
        {
            if (player2 == "🗿" || player2 == "🖖")
                return typeOfPlays::POINT_PLAYER_1;
            else if (player2 == "✂️" || player2 == "🦎")
                return typeOfPlays::POINT_PLAYER_2;
        }
        else if (player1 == "✂️")
        {
            if (player2 == "📄" || player2 == "🦎")
                return typeOfPlays::POINT_PLAYER_1;
            else if (player2 == "🗿" || player2 == "🖖")
                return typeOfPlays::POINT_PLAYER_2;
        }
        else if (player1 == "🦎")
        {
            if (player2 == "📄" || player2 == "🖖")
                return typeOfPlays::POINT_PLAYER_1;
            else if (player2 == "🗿" || player2 == "✂️")
                return typeOfPlays::POINT_PLAYER_2;
        }
        else if (player1 == "🖖")
        {
            if (player2 == "✂️" || player2 == "🗿")
                return typeOfPlays::POINT_PLAYER_1;
            else if (player2 == "📄" || player2 == "🦎")
                return typeOfPlays::POINT_PLAYER_2;
        }

        return typeOfPlays::INVALID;
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