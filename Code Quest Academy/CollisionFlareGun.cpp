#include <string>
#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
	std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
	
	int n;
	std::cin >> n;
	std::cin.ignore();
	
	for (int i = 0; i < n; i++) {
		getOutput();
	}

	return 0;
}

void getOutput() {
	std::string info;
	getline(cin, info);

	std::stringstream ss(info);
        std::string temp;

	double nums[4];
	int i { 0 };

        while (getline(ss, temp, ',')) {
		nums[i] = std::stod(temp);
		i++;
	}

	cout << fixed << setprecision(2) << (nums[0]*nums[1] + nums[2]*nums[3])/(nums[1] + nums[3]) << "\n";
}

