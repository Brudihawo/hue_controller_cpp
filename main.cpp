#include <iostream>
#include "HTTPRequest.hpp"
#include "hue_bridge.h"
#include <string>
#include <sstream>
#include <unordered_set>
#include <regex>

int main(){
    HueBridge bridge("http://192.168.178.28/");
    bridge.SetUsername("VfjRO29GnJx3FRfqkcYwW6wfMnw5NzaHyCNQdAHI");

}