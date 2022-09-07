#include <iostream>
#include <fstream>
#include <string>

int	check_input(int argc, char *argv[]);
int	print_error(std::string str);

int	main(int argc, char *argv[])
{
	if (check_input(argc, argv))
		return (print_error("input error\n"));

	std::string filename = argv[1];
	std::ifstream ifs; // ifs(filename);
	ifs.open(filename);
	if (ifs.fail()) // fail or is_open
		return (print_error("file open error\n"));

	std::ofstream ofs;
	ofs.open(filename.append(".replace"));
	if (ofs.fail())
	{
		ifs.close();
		return (print_error("file create error\n"));
	}

	std::string	line;
	size_t		pos;
	size_t		rPos;
	size_t		rSize = std::strlen(argv[2]);
	while (std::getline(ifs, line))
	{
		rPos = 0;
		while (true)
		{
			pos = line.find(argv[2], rPos);
			if (pos == std::string::npos)
			{
				ofs << line.substr(rPos, line.length() - rPos) << '\n';
				break;
			}
			ofs << line.substr(rPos, pos - rPos) << argv[3];
			rPos = pos + rSize;
		}
	}
	ifs.close();
	ofs.close();

	return (0);
}

int	check_input(int argc, char *argv[])
{
	if (argc != 4 || std::strlen(argv[1]) == 0 || std::strlen(argv[2]) == 0)
		return (1);
	return (0);
}

int	print_error(std::string str)
{
	std::cout << str;
	return (1);
}