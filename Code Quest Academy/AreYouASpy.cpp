#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>

std::string removePunctuation(const std::string &result);
void getOutput(); 

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		getOutput();
	}
	return 0;
}
std::string removePunctuation(const std::string &result) {
	std::string input = result;
	input.erase(std::remove_if(input.begin(), input.end(), [](unsigned char c) {return std::ispunct(c); }), input.end());
	return input;
}

void getOutput() {
	std::string input;
	getline(std::cin, input);
	getline(std::cin, input);
	
	input = removePunctuation(input);

	std::string firstSentence = input.substr(0, input.find("|"));
	std::string secondSentence = input.substr(input.find("|")+1);

	firstSentence.erase(std::remove_if(firstSentence.begin(), firstSentence.end(), [&secondSentence](char c) {
        		return secondSentence.find(c) != std::string::npos;
    		}), firstSentence.end());

	// length == 0, not spy
	
	if (firstSentence.length() == 0) {
		std::cout << "That's my secret contact!";
	}
	else {
		std::cout << "You're not a secret agent!";
		
	}
}
