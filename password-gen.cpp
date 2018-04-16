#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

int main(int argc, char *argv[])
{
	int N = 8;
	bool isDigit = false;
	bool isChar = true;
	bool isSpec = false;
	std::string out = "";

	for (int i = 1; i < argc; ++i)
	{
		std::string arg = argv[i];
		if (arg == "--num" || arg == "-n")
		{
			isDigit = true;
			continue;
		}

		if (arg == "--char" || arg == "-c")
		{
			isChar = false;
			continue;
		}

		if (arg == "--spec" || arg == "-s")
		{
			isSpec = true;
		}

		N = atoi(argv[i]);

		if (N < 1) N = 8;
	}

	srand( (unsigned)time(NULL) );

	for (int i = 0; i < N; ++i)
	{
		char mod = rand() % 3;
		if (mod == 0 && isChar)
		{
			bool upperCase = rand() % 2;
			char ch;
			if (upperCase) ch = rand() % 25 + 65;
			else ch = rand() % 25 + 97;
			out += ch;
			continue;
		}

		if (mod == 1 && isDigit)
		{
			char ch = rand() % 10 + 48;
			out += ch;
			continue;
		}

		if (mod == 2 && isSpec)
		{
			char ch = rand() % 15 + 33;
			out += ch;
			continue;
		}
		--i;
	}

	std::cout << out << '\n';

	return 0;
}
