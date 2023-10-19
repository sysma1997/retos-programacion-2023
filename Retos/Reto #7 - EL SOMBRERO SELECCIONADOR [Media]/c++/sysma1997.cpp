#include <iostream>
#include <vector>
#include <tuple>
#include <map>

using namespace std;

class HatQuestion
{
public:
    string question;
    vector<tuple<string, string>> answers;
    int answer;

    HatQuestion(string question,
                vector<tuple<string, string>> answers)
    {
        this->question = question;
        this->answers = answers;
    }
    ~HatQuestion() {}
};
map<string, int> houses{{"Gryffindor", 0},
                        {"Slytherin", 0},
                        {"Hufflepuff", 0},
                        {"Ravenclaw", 0}};

int main()
{
    vector<HatQuestion> hatQuestions = {
        HatQuestion("¿Como te definirias?",
                    {make_tuple("1. Valiente", "Gryffindor"),
                     make_tuple("2. Leal", "Hufflepuff"),
                     make_tuple("3. Sabio", "Ravenclaw"),
                     make_tuple("4. Ambicioso", "Slytherin")}),
        HatQuestion("¿Cual es tu clase favorita?",
                    {make_tuple("1. Vuelo", "Gryffindor"),
                     make_tuple("2. Pociones", "Ravenclaw"),
                     make_tuple("3. Defensa contra las artes oscuras", "Slytherin"),
                     make_tuple("4. Animales fantasticos", "Hufflepuff")}),
        HatQuestion("¿Donde pasarias mas tiempo?",
                    {make_tuple("1. Invernadero", "Hufflepuff"),
                     make_tuple("2. Biblioteca", "Ravenclaw"),
                     make_tuple("3. En la sala comun", "Slytherin"),
                     make_tuple("4. Explorando", "Gryffindor")}),
        HatQuestion("¿Cual es tu color favorito?",
                    {make_tuple("1. Rojo", "Gryffindor"),
                     make_tuple("2. Azul", "Ravenclaw"),
                     make_tuple("3. Verde", "Slytherin"),
                     make_tuple("4. Amarillo", "Hufflepuff")}),
        HatQuestion("¿Cual es tu mascota?",
                    {make_tuple("1. Sapo", "Ravenclaw"),
                     make_tuple("2. Lechuza", "Gryffindor"),
                     make_tuple("3. Gato", "Hufflepuff"),
                     make_tuple("4. Serpiente", "Slytherin")}),
    };

    for (int i = 0; i < hatQuestions.size(); i++)
    {
        HatQuestion hatQuestion = hatQuestions[i];

        cout << hatQuestion.question << '\n';
        for (tuple<string, string> answer : hatQuestion.answers)
            cout << get<0>(answer) << '\n';

        while (true)
        {
            cout << "Responde con 1, 2, 3 o 4: ";
            int answer{0};
            cin >> answer;
            cout << '\n';

            if (answer > 0 && answer < 5)
            {
                hatQuestions[i].answer = answer - 1;
                break;
            }

            cout << "Respuesta invalida\n";
        }
    }

    for (HatQuestion hatQuestion : hatQuestions)
    {
        string house = get<1>(hatQuestion.answers[hatQuestion.answer]);
        houses[house] += 1;
    }
    string house{};
    int mostPoints{0};
    for (auto const &[key, value] : houses)
    {
        if (value > mostPoints)
        {
            mostPoints = value;
            house = key;
        }

        cout << key << ": " << value << ", ";
    }
    cout << '\n';

    cout << "Lo tengo claro... ¡" << house << "!\n";

    return 0;
}