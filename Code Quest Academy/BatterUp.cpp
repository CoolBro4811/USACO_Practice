#include <string>
#include <bits/stdc++.h>

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
	getline(std::cin, info);

	std::string name { info.substr(0, info.find(":")) };

	info = info.substr(info.find(":") + 1);
	int index = info.find(",");

	int total { 0 };
	int atBats { 0 };

	std::stringstream ss(info);
    	std::string temp;

	while (getline(ss, temp, ',')) {
		if (temp == "BB") {
			continue;
		}
		else if (temp == "1B") {
			total += 1;
		// 	std::cout << "found 1B" << "\n";
		}
		else if (temp == "2B") {
			total += 2;
		// 	std::cout << "found 2B" << "\n";
		}
		else if (temp == "3B") {
			total += 3;
		// 	std::cout << "found 3B" << "\n";
		}
		else if (temp == "HR") {
			total += 4;
		// 	std::cout << "found HR" << "\n";
		}
		atBats++;
	}
	// std::cout << total << ":" << atBats;
	std::cout << name << "=" << std::fixed << std::setprecision(3) << (total == 0 ? 0.000 : static_cast<float>(total)/atBats) << "\n";
}

