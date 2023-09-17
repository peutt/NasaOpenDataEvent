#include <iostream>
#include <string>
#include <curl/curl.h>

// Fonction de rappel pour stocker la réponse HTTP
size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t total_size = size * nmemb;
    output->append(static_cast<char*>(contents), total_size);
    return total_size;
}

int main() {
    // Initialiser libcurl
    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Erreur lors de l'initialisation de libcurl." << std::endl;
        return 1;
    }

    // URL à partir de laquelle on obtient leJSON
    std::string url = "https://www.alphavantage.co/query?function=TIME_SERIES_INTRADAY&symbol=IBM&interval=5min&apikey=WN32ZXLWA3QW33P1";

    // Initialiser la réponse
    std::string response;

    // Configurer la requête HTTP GET
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    // Exécute la requête HTTP GET
    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        std::cerr << "Erreur lors de l'exécution de la requête : " << curl_easy_strerror(res) << std::endl;
        curl_easy_cleanup(curl);
        return 1;
    }

    // Fermer libcurl
    curl_easy_cleanup(curl);

    //le JSON dans la chaîne 'response'
    std::cout << "Réponse JSON : " << response << std::endl;



    return 0;
}
