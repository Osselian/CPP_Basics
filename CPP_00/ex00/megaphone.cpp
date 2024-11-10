#include <cstring>
#include <iostream>
#include <ctype.h>

char	*strtoupper(char *str)
{
	int len;

	len = strlen(str);
	for (int i = 0; i < len; i++)
		str[i] = toupper(str[i]);
	return (str);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else 
	{
		for (int i = 1; i < argc; i++)
			std::cout << strtoupper(argv[i]) << " ";
		std::cout << std::endl;
	}
	return (0);
}