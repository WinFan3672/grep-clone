#include <iostream>
#include <regex>
#include <string>

void grep(std::string pattern, std::string data)
{
	std::stringstream ss(data);
	std::string t;
	char del = '\n';

	int i = 0;
	while (getline(ss, t, del))
	{
		if (t.find(pattern) != std::string::npos)
		{
			std::cout << t << "\n";
		}
	}
}

void show_help(char *argv[])
{
	std::cout << "usage: " << argv[0] << " [pattern]\n";
}

int main(int argc, char *argv[])
{

	if (argc == 1 or argc > 2)
	{
		show_help(argv);
		return -1;
	}

	// First we initialise the data
	std::string pattern;
    std::string data((std::istreambuf_iterator<char>(std::cin)),
                      std::istreambuf_iterator<char>());
	
	pattern = argv[1];

	// Finally we do the actual grepping
	grep(pattern, data);
}

