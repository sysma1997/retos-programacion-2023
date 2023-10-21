#include <iostream>
#include <curl/curl.h> // -lcurl
#include <json/json.h> // -ljsoncpp
// for compile success: g++ [name].cpp -o [name] -lcurl -ljsoncpp

// https://api.chucknorris.io/jokes/random

using namespace std;

void testJson()
{
    Json::Value test;
    test["id"] = 1116277134;
    test["name"] = "Sebastian Moreno Acero";
    test["age"] = 26.1;

    cout << Json::FastWriter().write(test) << '\n';
}

int main()
{
    CURL *easyHandle = curl_easy_init();
    auto res = curl_easy_setopt(easyHandle,
                                CURLOPT_URL,
                                "https://api.chucknorris.io/jokes/random");

    cout << res << '\n';

    return 0;
}