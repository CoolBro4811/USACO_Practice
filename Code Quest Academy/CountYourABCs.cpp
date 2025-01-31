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

void getOutput() {
	pair<char, int> letters[26];
	
	for (int i = 0; i < 26; i++) {
		letters[i] = make_pair('a' + i, 0);
	}

	string temp;

	getline(cin, temp);

	for (char l : temp) {
		if (isalpha(l)) {
			l = tolower(l);
			int index = l - 'a';
			letters[index].second += 1;
		}
	}
	int max = 0;
	for (pair<char, int> p : letters) {
		if (max < p.second) max = p.second;
	}

	cout << max << "\n";
}

