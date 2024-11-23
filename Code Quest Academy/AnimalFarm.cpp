#include <iostream>
#include <cstdio>

void getOutput();

int main() {
	int n;
	scanf("%d", &n);

	std::string dummy;
	getline(std::cin, dummy);

	for (int i = 0; i < n; i++) {
		getOutput();
	}
	return 0;
}

void getOutput() {
	int t, g, h;
	scanf("%d %d %d", &t, &g, &h);
	printf("%d\n", t*2+4*(g+h));
}
