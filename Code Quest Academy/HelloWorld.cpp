#include <iostream>

void printOutput();

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        printOutput();
    }

    return 0;
}

void printOutput() {
    std::string temp;
    std::cin >> temp;
    std::cout << temp << "\n";
    return;
}