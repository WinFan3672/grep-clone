CC = clang++

release:
	$(CC) main.cpp -o grep.app
debug:
	$(CC) -g main.cpp -o grep-debug.app
