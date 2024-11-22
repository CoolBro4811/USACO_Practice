#include <iostream>
#include <cstdio>

void printOutput();

int main() {
    int n;
    std::cin >> n;
    std::string temp;
    getline(std::cin, temp);
    for (int i = 0; i < n; i++) {
        printOutput();
    }

    return 0;
}

void printOutput() {
    std::string temp;
    std::cin >> temp;
    printf("%s", temp.c_str());
    return;
}