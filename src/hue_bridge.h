#pragma once

#include <string>
#include <vector>

class HueBridge {
    private:
        std::string m_ip;
        std::string m_username;
        std::vector<std::pair<std::string, std::string>> m_lights;
    
    public:
        HueBridge(std::string ip);
        ~HueBridge();

        bool LightOn(std::string light_name);
        bool LightOff(std::string light_name);
        bool RefreshLights();
        void SetUsername(std::string username);
};