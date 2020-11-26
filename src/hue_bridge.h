#pragma once

#include <string>

class hue_bridge {
    private:
        std::string m_ip;
    
    public:
        hue_bridge(std::string ip);
        ~hue_bridge();

        bool light_on(std::string light_name);
        bool light_off(std::string light_name);
};