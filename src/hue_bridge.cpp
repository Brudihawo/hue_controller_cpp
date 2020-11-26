#include "hue_bridge.h"
#include "HTTPRequest.hpp"
#include <iostream>


hue_bridge::hue_bridge(std::string ip):m_ip(ip) {
    try {
    http::Request request(m_ip);

    const http::Response response = request.send("GET");
    std::cout << std::string(response.body.begin(), response.body.end()) << std::endl;
    } catch (const std::exception e) {
        std::cerr << "HTTP request failed, error:" << e.what() << std::endl;
    }
}

hue_bridge::~hue_bridge() {
    
}

bool hue_bridge::light_on(std::string light_name) {
    return true; 
}

bool hue_bridge::light_off(std::string light_name) {
    return true;
}
