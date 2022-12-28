#include <vector>
#include <string>
#include <fstream>
#include <iostream>

const char* INPUT_PATH = "inputs/Day1.txt";

int main() {
    std::ifstream file;

    file.open(INPUT_PATH);

    std::string line;
    int curNum = 0;
    unsigned int biggestNum = 0;
    
    if (file.is_open()) {
        while (file) {
            std::getline(file, line);
            if (line != "") {
                curNum += std::stoi(line);
            } else {
                if (curNum >= biggestNum) {
                    biggestNum = curNum;
                }
                curNum = 0;
            }
        }
    } else {
        std::cout << "ERROR: Couldn't open file.";
        return 0;
    }

    std::cout << biggestNum;
}