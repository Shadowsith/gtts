#ifndef GTTS_H
#define GTTS_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <sstream>

namespace gtts {

class GoogleTTS {
    private:

    // std::string _bla = "curl 'https://translate.google.com/translate_tts?ie=UTF-8&q=Hello%20Everyone&tl=en&client=tw-ob' -H 'Referer: http://translate.google.com/' -H 'User-Agent: stagefright/1.2 (Linux;Android 5.0)' > google_tts.mp3";
    std::string _curl = "curl 'https://translate.google.com/translate_tts?ie=UTF-8&q=";
    std::string _lang = "&tl=";
    std::string _text = "";
    std::string _client = "&client=tw-ob' ";
    std::string _out = "> /tmp/gtts.mp3";
    std::string _outv = "> /tmp/gtts_"; 
    std::string _ref = " 'Referer: http://translate.google.com/' ";
    std::string _agent = " 'User-Agent: stagefright/1.2 (Linux;Android 9.0)' ";
    std::string _mpv = "mpv";
    std::string _speed = " --speed=";
    std::string _play = " /tmp/gtts.mp3 1>/dev/null";
    std::string _cat = "cat /tmp/gtts_*.mp3 > /tmp/gtts.mp3";
    std::string _rm = "rm /tmp/gtts_*.mp3";

    std::vector<std::string> _cmds;

    void parse(std::vector<std::string>& vec);
    void parse();
    std::vector<std::string> split(std::string& msg);
    void replace(std::string& text);
    void unite();

    public:
    GoogleTTS(std::string msg, std::string lang, std::string speed = "1.0"); 
    void execute();
    static void help();
    static void version();
};

}

#endif //GTTS_H
