#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

bool has_2digit(const std::string & str) {
	std::stringstream sstream(str);
	int num;
	std::string word;
	while (sstream.good()) {
		sstream >> word;
		std::stringstream wordstream(word);
		if (wordstream >> num && ((num > 9 && num < 100) || (num < -9 && num > -100))) {
			return true;
		}
		else {
			wordstream.clear();
		}
	}
	return false;
}

int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "\n>>> usage: program filename\n";
		return 1;
	}
	std::string filename = argv[1];
	std::fstream fin(filename);
	if (!fin.good()) {
		std::cout << "\n>>> file not found";
		std::cout << "\n>>> usage: program filename\n";
		return 1;
	}
	else {
		std::string line;
		while (std::getline(fin, line)) {
			if (!has_2digit(line)) {
				std::cout << line << std::endl;
			}
		}
	}
}