#include "./gtts.h"

namespace gtts {

GoogleTTS::GoogleTTS(std::string msg, std::string lang, std::string speed) {
    _speed += speed;
    _lang += lang;
    if(msg.length() > 200) {
        std::vector<std::string> msgs = this->split(msg);
        this->parse(msgs);
    } else {
        _text = msg;
        this->parse();
    }
}

std::vector<std::string> GoogleTTS::split(std::string& msg) {
    std::vector<std::string> vec;
    std::istringstream iss(msg);
    std::vector<std::string> words(std::istream_iterator<std::string>{iss},
            std::istream_iterator<std::string>());
    std::string part = "";
    for(std::string s : words) {
        if(part.size()-1 + s.size() <= 200) {
            part += s + " ";
        } else {
            vec.push_back(part);
            part = s + " ";
        }
    }
    if(part != "") vec.push_back(part);

    return vec;
}

void GoogleTTS::unite() {
    system(_cat.c_str());
    system(_rm.c_str());
}

void GoogleTTS::execute() {
    if(_cmds.size() == 1) {
        std::system(_cmds[0].c_str());
    } else {
        for(std::string cmd : _cmds) {
            std::system(cmd.c_str());
        }
        this->unite();
    }
    _mpv += _speed + _play;
    std::system(_mpv.c_str());
}

void GoogleTTS::replace(std::string& text) {
    size_t start_pos = 0;
    while((start_pos = text.find(" ", start_pos)) != std::string::npos) {
       text.replace(start_pos, 1, "%20");
       start_pos += 3; // Handles case where 'to' is a substring of 'from'
    }
}

void GoogleTTS::parse() {
    this->replace(_text);
    std::string cmd = _curl + _text + _lang + _client + "-H" + _ref + "-H";
    cmd += _agent + _out + " 2>/dev/null"; 
    _cmds.push_back(cmd);
}

void GoogleTTS::parse(std::vector<std::string>& vec) {
    std::string cmd = "";
    int i = 0;
    for(std::string msg : vec) {
        this->replace(msg);
        cmd = _curl + msg + _lang + _client + "-H" + _ref + "-H";
        cmd += _agent + _outv + std::to_string(i) + ".mp3" + " 2>/dev/null"; 
        _cmds.push_back(cmd);
        i++;
    }
}

void GoogleTTS::help() {
    std::cout << "gtts: plays Google Text-to-Speech speech synthesis with help of Google Translate voice" << std::endl;
    std::cout << "Usage: gtts [language] [message] ([speed])" << std::endl;
    std::cout << "standard speed is 1.0" << std::endl;
    std::cout << std::endl;
    std::cout << "Options:" << std::endl;    
    std::cout << "-h\t\tshows this help" << std::endl;
    std::cout << "-v\t\tshows program version" << std::endl;
    std::cout << "-l\t\tshows all available languages" << std::endl;
    std::cout << std::endl;
}

void GoogleTTS::version() {
    std::cout << "gtts version: 0.1" << std::endl;
}

}
