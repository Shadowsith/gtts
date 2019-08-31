#ifndef GTTS_H
#define GTTS_H

#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <sstream>
#include <map>

namespace gtts {
    typedef std::string string;

    const std::map<string, string> lang_codes {
        {"af", "Afrikaans"},
        {"sq", "Albanian"},
        {"ar", "Arabic"},
        {"hy", "Armenian"},
        {"az", "Azerbaijani"},
        {"eu", "Basque"},
        {"be", "Belarusian"},
        {"bn", "Bengali"},
        {"bs", "Bosnian"},
        {"km", "Cambodian"},
        {"ca", "Catalan"},
        {"zh-CN", "Chinese (Simplified)"},
        {"zh-TW", "Chinese (Traditional)"},
        {"hr", "Croatian"},
        {"cs", "Czech"},
        {"da", "Danish"},
        {"nl", "Dutch"},
        {"en", "English"},
        {"eo", "Esperanto"},
        {"et", "Estonian"},
        {"tl", "Filipino"},
        {"fi", "Finnish"},
        {"fr", "French"},
        {"ka", "Georgian"},
        {"de", "German"},
        {"el", "Greek"},
        {"gu", "Gujarati"},
        {"hi", "Hindi"},
        {"hu", "Hungarian"},
        {"is", "Icelandic"},
        {"id", "Indonesian"},
        {"it", "Italian"},
        {"ja", "Japanese"},
        {"jw", "Javanese"},
        {"kn", "Kannada"},
        {"ko", "Korean"},
        {"la", "Latin"},
        {"lv", "Latvian"},
        {"mk", "Macedonian"},
        {"ml", "Malayalam"},
        {"mr", "Marathi"},
        {"mo", "Moldavian"},
        {"sr-ME", "Montenegrin"},
        {"ne", "Nepali"},
        {"no", "Norwegian"},
        {"pl", "Polish"},
        {"pt-BR", "Portuguese (Brazil)"},
        {"pt-PT", "Portuguese (Portugal)"},
        {"ro", "Romanian"},
        {"ru", "Russian"},
        {"sr", "Serbian"},
        {"sh", "Serbo-Croatian"},
        {"si", "Sinhalese"},
        {"sk", "Slovak"},
        {"sl", "Slovenian"},
        {"es", "Spanish"},
        {"es-419", "Spanish (Latin American)"},
        {"su", "Sundanese"},
        {"sw", "Swahili"},
        {"sv", "Swedish"},
        {"ta", "Tamil"},
        {"te", "Telugu"},
        {"th", "Thai"},
        {"tr", "Turkish"},
        {"uk", "Ukrainian"},
        {"ur", "Urdu"},
        {"vi", "Vietnamese"},
        {"cy", "Welsh"},
    };

    class GoogleTTS {
        private:

        string _curl =
            "curl 'https://translate.google.com/translate_tts?ie=UTF-8&q=";
        string _lang = "&tl=";
        string _text = "";
        string _client = "&client=tw-ob' ";
        string _out = "> /tmp/gtts.mp3";
        string _outv = "> /tmp/gtts_"; 
        string _ref = " 'Referer: http://translate.google.com/' ";
        string _agent = " 'User-Agent: stagefright/1.2 (Linux;Android 9.0)' ";
        string _mpv = "mpv";
        string _speed = " --speed=";
        string _play = " /tmp/gtts.mp3 1>/dev/null";
        string _cat = "cat /tmp/gtts_*.mp3 > /tmp/gtts.mp3";
        string _rm = "rm /tmp/gtts_*.mp3";

        std::vector<string> _cmds;

        void parse(std::vector<string>& vec);
        void parse();
        std::vector<string> split(string& msg);
        void replace(string& text);
        void unite();

        public:
        GoogleTTS(string msg, string lang, string speed = "1.0"); 
        void execute();
        static void help();
        static void version();
        static void languages();
    };

}

#endif //GTTS_H
