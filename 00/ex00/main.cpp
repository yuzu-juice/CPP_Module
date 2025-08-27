# include <iostream>

std::string	megaphone(std::string str);

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; i < argc; i++)
	{
		std::cout << megaphone(argv[i]);
	}
	std::cout << std::endl;
	return (0);
}

std::string	megaphone(std::string s)
{
	std::string	transformed_s;

	for (std::string::iterator it = s.begin(); it != s.end(); it++)
	{
		transformed_s += std::toupper(*it);
	}
	return (transformed_s);
}
