#include <vector>
#include <string>
#include <fstream>
#include <iostream>

const char* INPUT_PATH = "inputs/Day1.txt";

int main() {
    std::ifstream file;
    std::vector<int> lines;

    file.open(INPUT_PATH);

    std::string line;

    if (file.is_open()) {
        while (file) {
            std::getline(file, line);
            if (line != "") {
                lines.push_back(std::stoi(line));
            } else {
                lines.push_back(-1);
            }
        }
    } else {
        std::cout << "couldn't open file";
        return 0;
    }
    std::cout << lines.size() << std::endl;

    int cur = 0;
    unsigned int biggestNum = 0;
    for (int i = 0; i < lines.size(); i++) {
        if (lines[i] != -1) {
            cur += lines[i];
        } else {
            std::cout << cur << std::endl;
            if (cur >= biggestNum) {
                biggestNum = cur;
            }
            cur = 0;
        }
    }

    std::cout << biggestNum;
}