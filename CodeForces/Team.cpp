#include <bits/stdc++.h>
#include <cstdint>
using namespace std;


int getOutput();

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	uint16_t n;
	std::cin >> n;

	int sum = 0;

	for (int i = 0; i < n; i++) {
		uint8_t sure = getOutput();
		sum += (sure >= 2 ? 1 : 0);
	}
	cout << sum;
}

int getOutput() {
	bool x, y, z;
	cin >> x >> y >> z;
	return x + y + z;
}
