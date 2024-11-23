#include <cstdio>
#include <iostream>
#include <vector>

int getOutput();

int main() {
    int n;
    scanf("%d", &n);
    std::string dummy;
    std::getline(std::cin, dummy);

    for (int i = 0; i < n; i++) {
        printf("%d%s", getOutput(), "\n");
    }
    return 0;
}

int getOutput() {
    std::string vowels("aeiou");

    std::string input;
    std::getline(std::cin, input);

    int count = 0;

    for (char i : input) {
        for (char vowel : vowels) {
            if (i == vowel) {
                count++;
                continue;
            }
        }
    }
    return count;
}