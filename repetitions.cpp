#include <iostream>
#include <string>

int main() {
    int n = 0;

    std::string word;

    std::cin >> word;

    int max_n = word.length() > 0 ? 1 : 0;

    std::string firstChar = std::to_string(word[0]);

    for (int i = 1; i < word.length(); i++) {
        
        if (firstChar.compare(std::to_string(word[i])) == 0) {
            n++;
        }
        else { max_n = std::max(n, max_n); n = 1; }
        std::cout << max_n;
        firstChar = std::string() + word[i];
        std::cout << firstChar;
    }
    std::cout << max_n;
    return 0;
}