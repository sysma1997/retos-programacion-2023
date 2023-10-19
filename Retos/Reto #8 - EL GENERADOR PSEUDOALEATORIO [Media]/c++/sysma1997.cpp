#include <iostream>
#include <chrono>

using namespace std;

int random();

int main()
{
    for (int i = 0; i < 100; i++)
        cout << random() << '\n';

    return 0;
}

int random()
{
    uint64_t ns = std::chrono::duration_cast<std::chrono::nanoseconds>(
                      std::chrono::high_resolution_clock::now().time_since_epoch())
                      .count();

    return ns % 101;
}