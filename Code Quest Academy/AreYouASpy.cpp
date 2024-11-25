#include <string>
#include <bits/stdc++.h>

std::string removePunctuation(const std::string &result);
std::string trim(const std::string &str);
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

std::string trim(const std::string &str) {
	// std::cout << str;
	size_t start = str.find_first_not_of(" 1234567890\t\n\r");
    	size_t end = str.find_last_not_of(" 1234567890\t\n\r");
    	return (start == std::string::npos) ? "" : str.substr(start, end - start + 1);
	// std::cout << str;
}

void getOutput() {
	std::string input;
	getline(std::cin, input);
	
	std::transform(input.begin(), input.end(), input.begin(), ::tolower);

	std::string firstSentence { input.substr(0, input.find("|")) };
	std::string secondSentence { input.substr(input.find("|")+1) };

	// std::cout << firstSentence << secondSentence << "\n";

	firstSentence = trim(firstSentence);
	secondSentence = trim(secondSentence);

	firstSentence = removePunctuation(firstSentence);
	secondSentence = removePunctuation(secondSentence);
	
	std::sort(firstSentence.begin(), firstSentence.end());
	std::sort(secondSentence.begin(), secondSentence.end());

	
	std::set<char> firstSet(firstSentence.begin(), firstSentence.end());
	firstSentence = std::string(firstSet.begin(), firstSet.end());

	std::set<char> secondSet(secondSentence.begin(), secondSentence.end());
	secondSentence = std::string(secondSet.begin(), secondSet.end());
    
	bool isValid = std::all_of(secondSet.begin(), secondSet.end(), [&](char c) {
        	return firstSet.count(c);
    	});

	// std::cout << firstSentence << secondSentence << "\n";
	
	// std::cout << firstSentence << secondSentence << "\n";

	if (isValid) {
		std::cout << "That's my secret contact!" << "\n";
	}	
	else {
		std::cout << "You're not a secret agent!" << "\n";
	}
}
