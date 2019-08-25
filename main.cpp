#include "./gtts.h"
#include <memory>

int main(int argc, char *argv[]) {
    typedef std::string string;
    switch(argc) {
        case 2:
            if (string("-h") == argv[1]
                || string("-H") == argv[1]
                || string("--help") == argv[1]) {
                gtts::GoogleTTS::help();
            }
            if (string("-v") == argv[1] || string("--version") == argv[1]) {
                gtts::GoogleTTS::version();
            }
            if (string("-l") == argv[1] || string("--languages") == argv[1]) {
                gtts::GoogleTTS::languages(); 
            }
            break;

        case 3: {
            string msg(argv[2]);
            string lang(argv[1]);
            std::unique_ptr<gtts::GoogleTTS>
                tts(new gtts::GoogleTTS(msg, lang));
            tts->execute();
            }
            break;

        case 4: {
            string msg(argv[2]);
            string lang(argv[1]);
            string speed(argv[3]);
            std::unique_ptr<gtts::GoogleTTS>
            tts(new gtts::GoogleTTS(msg, lang, speed));
            tts->execute();
            }
            break;

        default:
            gtts::GoogleTTS::help();
            break;
    }
    return 0;
}
