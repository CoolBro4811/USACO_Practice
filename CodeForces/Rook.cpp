#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;

		char a = temp[0];
		int pos = temp[1] - '0';

		string possible = "abcdefgh";

		int j = 0;
		for (auto &c : possible) {
			j++;
			if (c != a) cout << c << pos << "\n";
			if (j != pos) cout << a << j << "\n";
		}
	}
	return 0;
}
