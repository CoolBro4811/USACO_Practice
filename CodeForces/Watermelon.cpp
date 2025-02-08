#include <bits/stdc++.h>
#include <cstdint>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	uint16_t n;
	std::cin >> n;

	std::cout << (n != 0 && n > 3 && n % 2 == 0 ? "YES" : "NO");
}
