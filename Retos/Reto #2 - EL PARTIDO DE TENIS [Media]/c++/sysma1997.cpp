#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

const vector<string> score{"Love", "15", "30", "40"};

void tennisGame(vector<string> results);

int main()
{
    vector<string> results1{"P1", "P1", "P2", "P2", "P1", "P2", "P1", "P1"};
    vector<string> results2{"P1", "P1", "P1", "P3", "P1", "P1"};
    vector<string> results3{"P2", "P1", "P2", "P2", "P2"};
    vector<string> results4{"P1", "PX"};
    vector<string> results5{"P1", "P1", "P2", "P2", "P1", "P2", "P1", "P2", "P1", "P2", "P2"};

    tennisGame(results1);
    tennisGame(results2);
    tennisGame(results3);
    tennisGame(results4);
    tennisGame(results5);

    return 0;
}

void tennisGame(vector<string> results)
{
    int pointsP1{0}, pointsP2{0};
    bool isDeuce{false};

    for (int i = 0; i < results.size(); i++)
    {
        string player{results[i]};

        if (player == "P1")
            pointsP1 += 1;
        else if (player == "P2")
            pointsP2 += 1;
        else
        {
            cout << "Jugada no valida\n";
            continue;
        }

        string p1{};
        if (pointsP1 < score.size())
            p1 = score[pointsP1];
        string p2{};
        if (pointsP2 < score.size())
            p2 = score[pointsP2];

        if (pointsP1 == 3 && pointsP2 == 3)
        {
            isDeuce = true;
            cout << "Deuce\n";

            continue;
        }
        else if (!isDeuce && pointsP1 > 3)
            break;
        else if (!isDeuce && pointsP2 > 3)
            break;

        if (isDeuce)
        {
            int diff = abs(pointsP1 - pointsP2);

            if (diff == 0)
            {
                if (player == "P1")
                    pointsP2 -= 1;
                else
                    pointsP1 -= 1;

                diff = abs(pointsP1 - pointsP2);
            }
            if (diff != 0 && diff < 2)
            {
                cout << "Ventaja " << ((pointsP1 > pointsP2) ? "P1" : "P2") << '\n';

                continue;
            }
            else if (diff >= 2)
                break;
        }

        cout << p1 << " - " << p2 << '\n';
    }

    if (pointsP1 < 4 && pointsP2 < 4)
    {
        cout << "Partido incompleto\n\n";

        return;
    }

    cout << "Ha ganado el " << ((pointsP1 > pointsP2) ? "P1" : "P2") << "\n\n";
}