#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getOutput();
	}

	return 0;
}

void getOutput() {
	vector<string> lastDonors, thisDonors;
	string temp;
	getline(cin, temp);
	int index = 0;
	while (index = temp.find(',')) {
		lastDonors.push_back(temp.substr(0, index));
		temp = temp.substr(index+1, temp.length()-1-index);
	}

	getline(cin, temp);
	index = 0;
	while (index = temp.find(',')) {
		thisDonors.push_back(temp.substr(0, index));
		temp = temp.substr(index+1, temp.length()-1-index);
	}
	string both = "";
	string onlylast = "";
	string onlythis = "";


	for (int i = 0; i < lastDonors.size(); i++) {
		bool lastYear = false;
		for (int j = 0; j < thisDonors.size(); j++) {
			if (lastDonors[i] == thisDonors[j]) lastYear = true; break; thisDonors.erase(thisDonors.begin() + j);
		}
		if (lastYear) {both += lastDonors[i] + ","; continue;
		} else onlylast += lastDonors[i] + ","; continue;
	}
	cout << onlylast << "\n" << both << "\n";
	for (int i = 0; i < thisDonors.size(); i++) {
		onlythis += thisDonors[i] + ",";
	}
	cout << onlythis.substr(0, onlythis.begin()-onlythis.end()-1) << "\n";
}

