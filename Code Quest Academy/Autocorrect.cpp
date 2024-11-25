#include <string>
#include <bits/stdc++.h>

void getOutput();

int main() {
	std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
	
	int n;
	std::cin >> n;
	
	for (int i { 0 }; i < n; i++) {
		getOutput();
	}

	return 0;
}

int getHammingDistance(const std::string &str1, const std::string &str2);

void getOutput() {
	int dict_words;
	std::cin >> dict_words;
	// std::cout << dict_words << "\n";
	
	int misspelled_words;
	std::cin >> misspelled_words;
	// std::cout << misspelled_words << "\n";
	
	std::string* correctWords { new std::string[dict_words] };
	std::string* misspelledWords { new std::string[misspelled_words] };

	for (int i { 0 }; i < dict_words ; i++) {
		std::cin >> correctWords[i];
	}

	for (int i { 0 }; i < misspelled_words; i++) {
		std::cin >> misspelledWords[i];
	}
	
	for (int i = 0; i < misspelled_words; i++) {
		int minHammingDistance { INT_MAX };
		std::string bestMatch;

		for (int j = 0; j < dict_words; j++) {
			int distance { getHammingDistance(correctWords[j], misspelledWords[i]) };

			if (minHammingDistance > distance ||
				(distance == minHammingDistance && correctWords[j] > bestMatch)) {
				minHammingDistance = distance;
				bestMatch = correctWords[j];
			}
			// std::cout << "Comparing " << correctWords[j] << " with " << misspelledWords[i] 
          		// 	<< ": Distance = " << distance << "\n";
			// std::cout << "Current best match: " << bestMatch << " with distance " 
          		// 	<< minHammingDistance << "\n";
		}
		std::cout << bestMatch << "\n";
		minHammingDistance = INT_MAX;
		bestMatch = "";
	}
	return;
}

int getHammingDistance(const std::string &str1, const std::string &str2) {
	int count { 0 };
	
	for (int i { 0 }; i < std::min(str1.length(), str2.length()); i++) {
		if (str1[i] != str2[i]) {
			count++;
		}
	}
	
	int l1 = str1.length();
	int l2 = str2.length();

       	count = l1 > l2 || l2 > l1 ? INT_MAX : count;
	return count;
}
