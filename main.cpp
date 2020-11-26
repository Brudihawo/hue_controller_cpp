#include <iostream>
#include "HTTPRequest.hpp"
#include "hue_bridge.h"
#include "json.h"
#include <string>
#include <sstream>
#include <unordered_set>
#include <regex>

int main(){
    std::string body;
    try {
        http::Request request("http://192.168.178.28/api/VfjRO29GnJx3FRfqkcYwW6wfMnw5NzaHyCNQdAHI/lights/");
        
        const http::Response response = request.send("GET");
        body = std::string(response.body.begin(), response.body.end());    
    } catch (const std::exception& e) {
        std::cerr << "HTTP request failed, error:" << e.what() << std::endl;
    }
    // std::cout << body << std::endl << std::endl;
    std::smatch light_match;
    std::vector<std::pair<std::string, std::string>> lights;

    std::regex re("\"(\\d{2})\":.*?\"name\":\"(.*?)\"");
    while (std::regex_search(body, light_match, re)) {
        lights.push_back({light_match[1].str(), light_match[2].str()});

        std::cout << "Light ID: " << light_match[1].str() << ", Light Name: " << light_match[2].str() << ";" << std::endl;
        body = light_match.suffix();
    }
    
}