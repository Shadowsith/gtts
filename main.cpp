#include "./gtts.h"
#include <memory>

int main(int argc, char *argv[])
{
    if(argc == 3) {
        std::string msg(argv[2]);
        std::string lang(argv[1]);
        std::unique_ptr<gtts::GoogleTTS> tts(new gtts::GoogleTTS(msg, lang));
        tts->execute();
    } else if(argc == 4) {
        std::string msg(argv[2]);
        std::string lang(argv[1]);
        std::string speed(argv[3]);
        std::unique_ptr<gtts::GoogleTTS> tts(new gtts::GoogleTTS(msg, lang, speed));
        tts->execute();
    } else if(argc == 2) {
        if(argv[0] == "-h" || argv[0] == "-H") {
            gtts::GoogleTTS::help();
        }
        if(argv[0] == "-v") {
            gtts::GoogleTTS::version();
        }
    } else {
        gtts::GoogleTTS::help();
    }
    return 0;
}
