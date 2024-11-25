#include <string>
#include <bits/stdc++.h>

std::string removePunctuation(const std::string &result);
void getOutput(); 

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;
	std::cin.ignore();

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

	std::string firstSentence { input.substr(0, input.find("|")) };
	std::string secondSentence { input.substr(input.find("|")+1) };

	firstSentence = removePunctuation(firstSentence);
	secondSentence = removePunctuation(secondSentence);

	bool containsLetter { false };
	for (int i = 0; i < firstSentence.length(); i++) {
		for (int j = 0; j < secondSentence.length(); j++) {
			if (firstSentence[i] == secondSentence[j]) {
				containsLetter = true; 
				break;
			}
		}
		if (!containsLetter) {
			std::cout << "You're not a secret agent!";
			return;
		}
		containsLetter = false;
	}
	
	std::cout << "That's my secret contact!";
}
