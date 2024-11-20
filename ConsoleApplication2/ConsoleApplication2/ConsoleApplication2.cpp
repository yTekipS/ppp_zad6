#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

std::vector<std::string> Read() {
	std::vector<std::string> lines; 
	lines.reserve(110);
	std::string line;
	std::ifstream file("bin.txt");
	if (file) {
		while (file >> line)
		{
			lines.emplace_back(line);
		}
		return lines;
	}
}

int main() {

	std::vector <std::string> bin = Read();
	bin.reserve(110);
	std::vector <int> binTOint;
	binTOint.reserve(110);

	for (auto item : bin) {
		int num = 0;

		for (int i = 0; i < item.length(); i++) {
			if (item[i] == '1') {
				num += pow(2, item.length() - 1 - i);
			}
		}

		binTOint.emplace_back(num);
	}

	std::ofstream file("numbrs.txt");
	if (file) {
		for (auto item : binTOint) {
			std::string a = std::to_string(item) + "\n";
			file << a;
		}
	}

}