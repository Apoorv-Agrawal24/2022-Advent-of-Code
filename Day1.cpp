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
    unsigned int biggestNum1 = 0;
    unsigned int biggestNum2 = 0;
    unsigned int biggestNum3 = 0;
    
    if (file.is_open()) {
        while (file) {
            std::getline(file, line);
            if (line != "") {
                curNum += std::stoi(line);
            } else {
                if (curNum >= biggestNum1) {
                    biggestNum3 = biggestNum2;
                    biggestNum2 = biggestNum1;
                    biggestNum1 = curNum;
                } else if (curNum >= biggestNum2) {
                    biggestNum3 = biggestNum2;
                    biggestNum2 = curNum;
                }
                else if (curNum >= biggestNum3) {
                    biggestNum3 = curNum;
                }
                curNum = 0;
            }
        }
    } else {
        std::cout << "ERROR: Couldn't open file.";
        return 0;
    }

    std::cout << biggestNum1 + biggestNum2 + biggestNum3;
}