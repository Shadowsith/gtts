if ["$1" == "-u" -o "$1" == "--uninstall"]; then
    rm /usr/bin/gtts
else
    make
    sudo mv ./bin/gtts /usr/bin/
fi
