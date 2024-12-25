#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getOutput();
	}

	return 0;
}

void translateToNATO(const string &word) {

	map<char, string> natoAlphabet = {
        	{'A', "Alpha"},   {'B', "Bravo"},   {'C', "Charlie"}, {'D', "Delta"},
        	{'E', "Echo"},    {'F', "Foxtrot"}, {'G', "Golf"},    {'H', "Hotel"},
        	{'I', "India"},   {'J', "Juliet"}, {'K', "Kilo"},    {'L', "Lima"},
        	{'M', "Mike"},    {'N', "November"},{'O', "Oscar"},  {'P', "Papa"},
        	{'Q', "Quebec"},  {'R', "Romeo"},  {'S', "Sierra"},  {'T', "Tango"},
        	{'U', "Uniform"}, {'V', "Victor"}, {'W', "Whiskey"}, {'X', "Xray"},
        	{'Y', "Yankee"},  {'Z', "Zulu"}
    	};

	string res = "";
	for (char c : word) {
		if (c == ' ') { 
			if (!res.empty() && res.back() == '-') {
    				res.pop_back();
			}
			res += " "; 
			continue;
		}
		if (natoAlphabet.count(c)) {
    			res += natoAlphabet[c] + "-";
		}
	}

	if (!res.empty() && res.back() == '-') {
    		res.pop_back();
	}

	cout << res << "\n";
}

void getOutput() {
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string word;
		getline(cin, word);
		transform(word.begin(), word.end(), word.begin(), ::toupper);
		translateToNATO(word);
	}
}

