#include <string>
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
	int small, large, length;
	cin >> small >> large >> length;

	if (length == 0) {
    		cout << "true\n";
    		return;
	}

	int large_used = min(length/5, large);

	length -= large_used*5;

	cout << (length <= small ? "true\n" : "false\n");
}

