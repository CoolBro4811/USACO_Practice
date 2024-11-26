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
	int total { 0 };

	string temp;
	getline(cin, temp);


	if (temp.length() != 10) {
		cout << "INVALID\n"; 
		return;
	}

	for (int i { 0 }; i < 9; i++) {
		if (!isdigit(temp[i])) {
			cout << "INVALID\n"; 
			return;
		}

		total += (temp[i] - '0')*(10 - i);
		// cout << (temp[i] - '0')*(10 - i) << "\n";
	}
	
	int checkDigit { 0 };

	if (temp[9] == 'X') {
		checkDigit = 10;
	}
	else if (isdigit(temp[9])){
		checkDigit = temp[9] - '0';
	}
	else {
		cout << "INVALID\n"; 
		return;
	}



	// cout << checkDigit << " " << temp[9] << total << "\n";

	cout << ((total + checkDigit) % 11 == 0 ? "VALID\n" : "INVALID\n");

	return; 
}

