#include <iostream>
#include <cstdint>

int alg(uint64_t n, int x);

int main() {
        int num;
        std::cin >> num;
        for (int i = 0; i < num; i++) {
		int n;
		std::cin >> n;

		int x = alg(n, 1);
		std::cout << n << ":" << x << "\n";
	}
}

int alg(uint64_t n, int x) {
	return n == 1 ? x : alg(n % 2 == 0 ? n/2 : n*3+1, x+1);
}
