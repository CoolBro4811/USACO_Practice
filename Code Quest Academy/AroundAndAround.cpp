#include <string>
#include <bits/stdc++.h>

void getOutput();

int main() {
	std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
	
	int n;
	std::cin >> n;
	
	for (int i = 0; i < n; i++) {
		getOutput();
	}

	return 0;
}

void getOutput() {
	int altitude;
	std::cin >> altitude;

	std::cout << std::fixed << std::setprecision(1) << 2*M_PI * altitude + 40075 << "\n";
}

