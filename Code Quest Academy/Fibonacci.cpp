#include <string>
#include <bits/stdc++.h>
using namespace std;
// (25x^4 - 16 = 0)
// (5x^2-4)(5x^2+4) = 0
// x = 2i/sqrt5
// x = 2/sqrt5 << ?

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

bool isFibonacci(int64_t x) {
	int64_t n1, n2, t1, t2;
	n1 = 5 * x*x + 4;
	n2 = 5 * x*x - 4; 
	t1 = sqrt(n1);
	t2 = sqrt(n2);
	// perfect square
	return t1*t1 == n1 || t2*t2 == n2;
}

void getOutput() {
	int64_t num;
	cin >> num;
	cout << (isFibonacci(num) ? "TRUE" : "FALSE") << "\n";
}

