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
	string input;
	cin >> input;	
	double n = std::stod(input.substr(1));

	int price = n * 100;

	int coins[4] = {25, 10, 5, 1};
	string words[4] = {"Quarters", "Dimes", "Nickels", "Pennies"};
	
	cout << input << "\n";
	for (int i = 0; i < 4; i++) {
		int count = price / coins[i];
		price %= coins[i];
		cout << words[i] << "=" << count << "\n";
	}

}

