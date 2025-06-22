# include "main.hpp"

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < argc; i++)
	{
		std::string s = argv[i];
		for (std::size_t j = 0; j < s.size(); j++)
		{
			std::cout << (char)std::toupper(s[j]);
		}
	}
	std::cout << std::endl;
	return 0;
}
