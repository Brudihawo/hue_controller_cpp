#include "hue_bridge.h"
#include "HTTPRequest.hpp"
#include <iostream>
#include <regex>
#include <string>

HueBridge::HueBridge(std::string ip):m_ip(ip) {
    std::string body;
    
    try {
        http::Request request("http://192.168.178.28/api/VfjRO29GnJx3FRfqkcYwW6wfMnw5NzaHyCNQdAHI/lights/");
        
        const http::Response response = request.send("GET");
        body = std::string(response.body.begin(), response.body.end());    
    } catch (const std::exception& e) {
        std::cerr << "HTTP request failed, error:" << e.what() << std::endl;
    }

    std::smatch light_match;
    std::vector<std::pair<std::string, std::string>> lights;

    std::regex re("\"(\\d{2})\":.*?\"name\":\"(.*?)\"");
    while (std::regex_search(body, light_match, re)) {
        lights.push_back({light_match[1].str(), light_match[2].str()});

        std::cout << "Light ID: " << light_match[1].str() << ", Light Name: " << light_match[2].str() << ";" << std::endl;
        body = light_match.suffix();
    }
}

HueBridge::~HueBridge() {
    
}

void HueBridge::SetUsername(std::string username) {
    m_username = username;
}

bool HueBridge::RefreshLights() {
    // Resetting Light Vector
    m_lights.clear();

    // HTTP Request 
    std::string body;
    try {
        http::Request request(m_ip + "/api/" + m_username + "/lights/");
        
        const http::Response response = request.send("GET");
        body = std::string(response.body.begin(), response.body.end());
    } catch (const std::exception& e) {
        std::cerr << "HTTP request failed, error:" << e.what() << std::endl;
        return false;
    }

    // Parsing with Regex
    std::smatch light_match;
    std::regex re("\"(\\d{2})\":.*?\"name\":\"(.*?)\"");
    if(std::regex_search(body, light_match, re)) {
        while (std::regex_search(body, light_match, re)) {
            m_lights.push_back({light_match[1].str(), light_match[2].str()});

            std::cout << "Light ID: " << light_match[1].str() << ", Light Name: " << light_match[2].str() << ";" << std::endl;
            body = light_match.suffix();
        }
        return true;
    } else {
        return false;
    }
}

bool HueBridge::LightOn(std::string light_name) {
    return true; 
}

bool HueBridge::LightOff(std::string light_name) {
    return true;
}
