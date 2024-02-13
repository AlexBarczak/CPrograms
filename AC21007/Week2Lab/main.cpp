#include <iostream>
#include <curl/curl.h>
#include <stdlib.h>
#include <string.h>

#include "problem.h"
#include "node.h"

using namespace std;
using namespace search_infrastructure;

struct memory {
    char *response;
    size_t size;
};

static size_t cb(void *data, size_t size, size_t nmemb, void *clientp){
    size_t realsize = size*nmemb;
    memory *mem = (memory *)clientp;

    char *ptr = (char *)realloc(mem->response, mem->size + realsize + 1);
    if (!ptr)
    {
        return 0;
    }

    mem->response = ptr;
    memcpy(&(mem->response[mem->size]), data, realsize);
    mem->size += realsize;
    mem->response[mem->size] = 0;

    return realsize;
}

int main(int argc, char const *argv[])
{
    memory chunk = {0};
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://fromsoftbible.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, cb);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);
        res = curl_easy_perform(curl);

        if (res != CURLE_OK)
        {
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                    curl_easy_strerror(res));

            curl_easy_cleanup(curl);
        }

        cout << "Hello, World";
        //cout << chunk.response;
    }
    
    return 0;
}
