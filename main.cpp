#include <iostream>
#include <regex>
#include <string>
#include <CLI/CLI.hpp>

std::string print_bool(bool val)
{
	if (val == 1)
	{
		return "true";
	}
	else
	{
		return "false";
	}
}

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

int main(int argc, char *argv[])
{
	// First we initialise the data
	std::string pattern;
    std::string data((std::istreambuf_iterator<char>(std::cin)),
                      std::istreambuf_iterator<char>());

	// Next we create the CLI11 app
	CLI::App app  { "Grep clone." };
	app.add_option("pattern", pattern, "Pattern to match");

	// We parse the arguments
	CLI11_PARSE(app, argc, argv);

	// Finally we do the actual grepping
	grep(pattern, data);
}

