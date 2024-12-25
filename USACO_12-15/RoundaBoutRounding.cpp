#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
	std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
	
	int n;
	std::cin >> n;
	cin.ignore();
	
	for (int i = 0; i < n; i++) {
		getOutput();
	}

	return 0;
}

int bessie_round(int x, int p10) {
	if (x % p10 >= p10 / 2) {
		x += p10;
	}
	x -= x % p10;
	return x;
}

int elsie_round(int x, int p10) {
    	if (x < 10) {
        	return (x >= p10 / 2) ? p10 : 0;
    	}

	string s = to_string(x);
    	int n = s.size();	
	cout << "elsie rounding: " << s << "\n";
    	for (int i = n - 1; i > 0; i--) {
        	if (s[i] >= '5') {
            		if (i > 0) s[i-1]++;
            		s[i] = '0';
        	} else {
            		s[i] = '0';
        	}
		cout << s << "\n";
    	}
	bool carry = false;
	for (int i = 0; i < n; i++) {
        	if (s[i] > '9') {
            		if (i > 0) s[i - 1]++;
            		s[i] = '0';
			carry = true;
		}
        	cout << s << "\n";
	}
	
	if (carry || s[0] > '9') {
		s[0] = '0';
		s = "1" + s;
	}

	cout << s << endl;

    	return stoi(s);
}

void getOutput() {
	int n;
	cin >> n;

	int p10 = 10;
	while (p10 < n) p10 *= 10;

	int count = 0;

	for (int x = 2; x <= n; x++) {
		int bessie = bessie_round(x, p10/10);
		int elsie = elsie_round(x, p10/10);
		cout << "comp : " << bessie << ":" << elsie << " on number: " << x << "\n";
		if (bessie != elsie) {
			count++;
			cout << "BAD comp : " << bessie << ":" << elsie << " on number: " << x << "\n";
		}
	}
	cout << count << "\n";
}

