#include <iostream>
#include "HTTPRequest.hpp"
#include "hue_bridge.h"

int main() {
    try {
    http::Request request("http://192.168.178.28/api/VfjRO29GnJx3FRfqkcYwW6wfMnw5NzaHyCNQdAHI/lights/");

    const http::Response response = request.send("GET");
    std::cout << std::string(response.body.begin(), response.body.end()) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "HTTP request failed, error:" << e.what() << std::endl;
    }
}