#include <iostream>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <string>

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
	
	if (firstWord == secondWord) {
		printf("%s|%s = NOT AN ANAGRAM\n", firstWord.c_str(), secondWord.c_str());
		return;
	}

	std::string originalFirstWord(firstWord);
	std::string originalSecondWord(secondWord);

	std::sort(firstWord.begin(), firstWord.end());
	std::sort(secondWord.begin(), secondWord.end());
	
	if (firstWord == secondWord) {
		printf("%s|%s = ANAGRAM\n", originalFirstWord.c_str(), originalSecondWord.c_str());
	}
	else {
		printf("%s|%s = NOT AN ANAGRAM\n", originalFirstWord.c_str(), originalSecondWord.c_str());
	}
}
