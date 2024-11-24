#include <iostream>
#include <string>
#include <cstdio>

int main() {
    	int n = 1;

    	std::string word;

    	getline(std::cin, word);
    	int max_n = 1;    
	for (int i = 1; i < word.length(); i++) {
		if (word[i-1] == word[i]) {
			n++;
        	}
		else {
			max_n = std::max(n, max_n);
			n = 1;
		}
    	}

	max_n = std::max(n, max_n);
	printf("%d", max_n);
    	return 0;
}
