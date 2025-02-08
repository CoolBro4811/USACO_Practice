#include <bits/stdc++.h>
#include <cstdint>
using namespace std;


void getOutput();

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	uint16_t n;
	cin >> n;	

	for (int i = 0; i < n; i++) {
		getOutput();
	}
}

void getOutput() {
	uint8_t n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	if (n == 0) {
		cout << "NO\n";
		return;
	}

	uint8_t ones = 0;
	uint8_t twos = 0;

	string t;	
	getline(cin, t);

	istringstream temp(t);

	int i;

	while (temp >> i) {
		if (i == 1) ones++;
		else twos++;
	}


	// split twos into 2 groups
	// difference between them is at most 2
	// means that 1s must be even and greater than 0 if twos is odd
	//
	// if not odd, then both twos and ones must be even
	
	if (twos % 2 == 1) {
		cout << (ones > 1 && ones % 2 == 0 ? "YES\n" : "NO\n");
		return;
	}
	cout << (ones % 2 == 0 ? "YES\n" : "NO\n");
	return;
}
