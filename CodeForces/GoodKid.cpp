#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getOutput();
	}
	return 0;
}

void getOutput() {
	int digits;
	cin >> digits;
	cin.ignore();

	vector<int> numbers(digits);
	for (int i = 0; i < digits; i++) {
		cin >> numbers[i];
	}

	long long product = 1;
	int min_num = INT_MAX;

	for (int num : numbers) {
		if (num < min_num) { 
			min_num = num; 
		}
		product *= num;
	}

	product /= min_num;
	product *= (min_num + 1);
	cout << product << "\n";
}
