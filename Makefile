all:
	@mkdir -p ./bin
	@g++ gtts.cpp main.cpp -o ./bin/gtts

clean:
	@rm -r ./bin
