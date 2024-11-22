#include <iostream>
#include <vector>
#include <cstdint>

int main() {
	uint64_t n;
	std::cin >> n;


	std::vector<uint64_t>arr(n);
	
	for (uint64_t i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	uint64_t theoretical = n*(n+1)/2;

	uint64_t sum = 0;
	for (uint64_t num : arr) {
		sum += num;
	}
	
	std::cout << theoretical-sum;
	return 0;
}

