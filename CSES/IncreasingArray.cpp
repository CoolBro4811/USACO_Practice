#include <iostream>
#include <cstdint>
#include <cstdio>

int main() {
	int n;
	
	scanf("%d", &n);

	int32_t* nums = new int32_t[n];

	for (int i = 0; i < n; i++) {
		std::cin >> nums[i];
	}

	int64_t count = 0;

	for (int32_t i = 1; i < n; i++) {
		if (nums[i] < nums[i-1]) {
			count += nums[i-1] - nums[i];
			nums[i] = nums[i-1];
		}
	}
	printf("%ld", count);
	return 0;

}
