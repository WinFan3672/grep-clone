CC = clang++

debug:
	$(CC) -g main.cpp -o debug-grep.app
release:
	$(CC) main.cpp -o grep.app
clean:
	-rm *.app
