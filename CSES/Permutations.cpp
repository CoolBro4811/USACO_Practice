#include <iostream>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n;
	std::cin >> n;

	if (n == 2 || n == 3) {
		printf("%s", "NO SOLUTION");
	}
	else {
		for (int i = 2; i <= n; i += 2) {
			std::cout << i << " ";
		}
		for (int i = 1; i <= n; i +=2) {
			std::cout << i << " ";
		}
	}
	return 0;
}

