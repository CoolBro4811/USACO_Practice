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

	for (int i { 0 }; i < n; i++) {
		getOutput();
	}

	return 0;
}

void getOutput() {
	string str;
	getline(cin ,str);

	stringstream ss(str);
	
	string temp;
	
	int maxValue { INT_MIN }; 
	while (getline(ss, temp, ' ')) {
		if (!temp.empty()) {
			if (maxValue < stoi(temp)) {
				maxValue = stoi(temp);
			}
		}
	}
	cout << maxValue << "\n";
}

