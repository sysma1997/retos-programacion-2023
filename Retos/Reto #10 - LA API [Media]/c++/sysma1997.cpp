/*
For compile code install 2 libraries ljsoncpp and lcurl

terminal: g++ [name].cpp -o [name] -lcurl -ljsoncpp
*/

#include <iostream>
#include <curl/curl.h>
#include <json/json.h>

using namespace std;

static size_t curlWriteCallBack(void *contents, size_t size, size_t nmemb, void *userp)
{
    ((string *)userp)->append((char *)contents, size * nmemb);
    return size * nmemb;
}

int main()
{
    CURL *curl;
    CURLcode result;
    string readBuffer;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if (!curl)
    {
        cerr << "Error initializing curl\n";
        return -1;
    }

    curl_easy_setopt(curl, CURLOPT_URL, "https://api.chucknorris.io/jokes/random");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, curlWriteCallBack);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    result = curl_easy_perform(curl);

    if (result != CURLE_OK)
    {
        cerr << "Error during curl request: "
             << curl_easy_strerror(result) << '\n';
        return -1;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();

    Json::Value json;
    Json::Reader reader;
    if (!reader.parse(readBuffer, json))
    {
        cerr << "Error to parsing: " << readBuffer << '\n';
        return -1;
    }

    cout << "Chuck Norris API Result: " << json["value"] << '\n';

    return 0;
}