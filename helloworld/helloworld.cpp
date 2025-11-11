#include <iostream>
#include <string>
int main() {
    std::cout << "Input the names of the 6 ice creams!" << std::endl;
    std::string iceCreams[6];
    for (int i = 0; i < 6; ++i) {
        std::cout << "Ice Cream " << (i + 1) << ": ";
        std::getline(std::cin, iceCreams[i]);
    }
    std::cout << "Grade the ice creams with 1-5!" << std::endl;
    int grades[6];
    for (int i = 0; i < 6; ++i) {
        std::cout << "Grade for " << iceCreams[i] << ": ";
        std::cin >> grades[i];
        std::cin.ignore(); // To ignore the newline character after the integer input
        std::cout << iceCreams[i] << " has been graded " << grades[i] << "!" << std::endl;
    }
}