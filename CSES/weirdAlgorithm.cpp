#include <iostream>
#include <cstdint>

int alg(uint64_t n);

int main() {
	uint64_t n;
	std::cin >> n;
	alg(n);
}

int alg(uint64_t n) {
	std::cout << " " + std::to_string(n);
	return n == 1 ? n : alg(n % 2 == 0 ? n/2 : n*3+1);
}

