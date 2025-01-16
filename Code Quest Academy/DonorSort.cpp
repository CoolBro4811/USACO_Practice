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
	while (index != -1) {
		index = temp.find(',');
		lastDonors.push_back(temp.substr(0, index));
		temp = temp.substr(index+1, temp.length()-1-index);
	}

	getline(cin, temp);
	index = 0;
	while (index != -1) {
		index = temp.find(',');
		thisDonors.push_back(temp.substr(0, index));
		temp = temp.substr(index+1, temp.length()-1-index);
	}

	sort(lastDonors.begin(), lastDonors.end(), [](std::string a, std::string b) {return a<b;});
	sort(thisDonors.begin(), thisDonors.end(), [](std::string a, std::string b) {return a<b;});

	string both = "";
	string onlylast = "";
	string onlythis = "";


	for (int i = 0; i < lastDonors.size(); i++) {
		vector<string>::iterator index = find(thisDonors.begin(), thisDonors.end(), lastDonors[i]);
		if (index != thisDonors.end()) {
			// found
			both += lastDonors[i] + ",";
			thisDonors.erase(index);
		}
		else {
			onlylast += lastDonors[i] + ",";
		}
	}

	cout << onlylast.substr(0, onlylast.end()-onlylast.begin()-1) << "\n" << both.substr(0, both.end()-both.begin()-1) << "\n";

	for (int i = 0; i < thisDonors.size(); i++) {
		onlythis += thisDonors[i] + ",";
	}

	cout << onlythis.substr(0, onlythis.end()-onlythis.begin()-1) << "\n";
}
