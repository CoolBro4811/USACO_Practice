#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	
	int n;
	cin >> n;

	uint64_t x = 1, y = 1;

	for (int i = 0; i < n; i++) {
		uint64_t temp = x+y;
		y = x;
		x = temp;
		cout << temp << "\n";
	}
	cout << "done\n";
	return 0;
}
