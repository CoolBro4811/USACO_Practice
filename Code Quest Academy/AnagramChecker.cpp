#include <iostream>
#include <cstdio>

void getOutput();

int main() {
    int n;
    std::cin >> n;

    std::string dummy;
    getline(std::cin, dummy);

    for (int i = 0; i < n; i++) {
        getOutput();
    }
    return 0;
}

void getOutput() {
    std::string input;
    getline(std::cin, input);

    std::string firstWord(input.substr(0, input.find("|")));
    std::string secondWord(input.substr(input.find("|")+1, input.length()));

    if (firstWord.compare(secondWord) == 0) {
        printf("%s|%s %s%s", firstWord.c_str(), secondWord.c_str(), "= NOT AN ANAGRAM", "\n");
        return;
    }

    bool foundYet = true;

    for (int i = 0; i < firstWord.length(); i++) {
        for (int j = 0; j < secondWord.length(); j++) {
            if (!(foundYet) && firstWord[i] != secondWord[j]) {
                foundYet = false;
            }
        }
        if (foundYet == false) {
            printf("%s|%s %s%s", firstWord.c_str(), secondWord.c_str(), "= NOT AN ANAGRAM", "\n");
        }
    }
    printf("%s|%s %s%s", firstWord.c_str(), secondWord.c_str(), "= ANAGRAM", "\n");
}