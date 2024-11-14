#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

void replace(std::ifstream &from, std::ofstream &to, std::string toReplace, 
	std::string replaceWith)
{
	std::string buf;
	size_t pos;

	while (std::getline(from, buf))
	{
		pos = 0;
		while (toReplace.length() > 0 && pos != std::string::npos)
		{
			pos = buf.find(toReplace);
			if (pos != std::string::npos)
			{
				buf.erase(pos, toReplace.length());
				buf.insert(pos, replaceWith);
			}
		}
		to << buf;
		to << std::endl;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "Invalid number of arguments, 3 required!" << std::endl;
		return (1);
	}

	std::ifstream  from(argv[1]);
	if(!from.is_open())
	{
		std::cout << "ERROR: Can't open file " << argv[1] << std::endl;
		return (1);
	}
	std::string fromName = argv[1];

	std::string toName = fromName + ".replace";
	std::ofstream  to(toName.c_str());
	if(!to.is_open())
	{
		std::cout << "ERROR: Can't open file " << toName << std::endl;
		return (1);
	}

	replace(from, to, argv[2], argv[3]);
	
	from.close();
	to.close();
	return 0;
}