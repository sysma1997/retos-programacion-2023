#include <iostream>
#include <ctime>
#include <chrono>
#include <iomanip>

using namespace std;

bool isFriday13(int month, int year);

int main()
{
    auto boolString = [](bool result) -> string
    {
        return result ? "Yes" : "No";
    };

    cout << "Is 10/2023 friday 13: " << boolString(isFriday13(10, 2023)) << '\n';
    cout << "Is 05/2022 friday 13: " << boolString(isFriday13(5, 2022)) << '\n';
    cout << "Is 12/2021 friday 13: " << boolString(isFriday13(12, 2021)) << '\n';

    return 0;
}

bool isFriday13(int month, int year)
{
    tm tmStruct{};
    istringstream ss(to_string(year) + "-" + to_string(month) + "-13");
    ss >> get_time(&tmStruct, "%Y-%m-%d");
    chrono::system_clock::time_point timePoint{
        chrono::system_clock::from_time_t(mktime(&tmStruct))};
    time_t datetime{chrono::system_clock::to_time_t(timePoint)};

    tm *ltm{localtime(&datetime)};

    if (ltm->tm_wday == 5)
        return true;

    return false;
}