#include <bits/stdc++.h>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int testcases;
	std::cin >> testcases;

	for (int i = 0; i < testcases; i++) {
		int32_t r, c;
		scanf("%d %d", &r, &c);
		
		printf("%d %d", r, c);

		if (r == c && r == 1) std::cout << 1 << "\n"; continue;

		int32_t base = std::max(r, c);
		if (base % 2 == 1) { std::cout << static_cast<int32_t>(std::pow(base, 2) - 2*base + r + c) << "\n"; }
		else { std::cout << static_cast<int32_t>(std::pow(base, 2) + 2 - r - c) << "\n"; }
		std::cout << base;
	}
	return 0;
}
