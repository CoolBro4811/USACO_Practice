#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	size_t n;
	cin >> n;

	vector<string> words(n);


	for (string &temp : words) {
		cin >> temp;
		if (temp.length() > 10) {
			temp = temp.front() + to_string(temp.length()-2) + temp.back();
		}
	}

	for (int i = 0; i < n; i++) {
		cout << words[i] << (i < n-1 ? "\n" : "");
	}
}
