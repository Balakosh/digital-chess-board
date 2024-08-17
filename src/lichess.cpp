//
// Created by Akeman on 16-Aug-24.
//

#include <iostream>
#include <string>
#include <curl/curl.h>

#include "lichess.h"

std::string lichess::get_token() {
    const char* token = std::getenv("LICHESS_API_TOKEN");
    if (token == nullptr) {
        std::cerr << "Environment variable LICHESS_API_TOKEN not set!" << std::endl;
        return {};
    }

    return token;
}

void lichess::pgn_upload() {
    CURL *curl;
    CURLcode res;

    std::string pgn = R"(
    [Event "Live Chess"]
    [Site "Lichess"]
    [Date "2023.08.16"]
    [Round "-"]
    [White "Player1"]
    [Black "Player2"]
    [Result "1-0"]
    1. e4 e5 2. Nf3 Nc6 3. Bb5 a6 4. Ba4 Nf6 5. O-O Be7 6. Re1 b5 7. Bb3 d6 8. c3 O-O 9. h3
    )";

    std::string token = get_token();
    std::string url = "https://lichess.org/api/import";

    struct curl_slist *headers = NULL;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_CAINFO, "/etc/ssl/certs/ca-certificates.crt");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        std::string auth_header = "Authorization: Bearer " + token;
        headers = curl_slist_append(headers, auth_header.c_str());
        headers = curl_slist_append(headers, "Content-Type: application/x-www-form-urlencoded");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        char* escaped_pgn = curl_easy_escape(curl, pgn.c_str(), pgn.length());
        std::string post_data = "pgn=" + std::string(escaped_pgn);

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_data.c_str());

        res = curl_easy_perform(curl);

        if(res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        } else {
            std::cout << "PGN uploaded successfully!" << std::endl;
        }

        curl_free(escaped_pgn);
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}
