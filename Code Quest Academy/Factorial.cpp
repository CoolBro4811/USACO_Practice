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

void multiply(vector<int> &result, int x);

void getOutput() {
	int n;
      	cin >> n;
	
      	vector<int> result = { 1 };

	for (int i = 2; i <= n; i++) {
		multiply(result, i);
	}

	for (auto i = result.rbegin(); i != result.rend(); ++i) {
		cout << *i; // deref
	}

	cout << "\n";
}

void multiply(vector<int> &result, int x) {
	// little endianness
	int carry = 0; // overflow
	for (size_t i = 0; i < result.size(); i++) {
		int product = result[i]*x + carry;
		result[i] = product % 10;
		carry = product / 10;
	}

	while (carry) { // add extra overflow (carrying digits with addition)
		result.push_back(carry % 10);
		carry /= 10;
	}
}

