#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
	cout << "start" << endl;
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		cout << "loop " << i << endl;
		getOutput();
	}

	return 0;
}

void getOutput() {
cout << "start output" << endl;
	vector<string> lastDonors, thisDonors;
	string temp;
	getline(cin, temp);
	int index = 0;
	while (index != -1) {
		cout << "loop output while " << index << endl;
		index = temp.find(',');
		lastDonors.push_back(temp.substr(0, index));
		temp = temp.substr(index+1, temp.length()-1-index);
		cout << temp << "\n";
	}
	for (vector<string>::const_iterator i = lastDonors.begin(); i != lastDonors.end(); ++i) cout << *i << endl;


	getline(cin, temp);
	index = 0;
	while (index != -1) {
		cout << "loop 2 output while " << index << endl;
		index = temp.find(',');
		thisDonors.push_back(temp.substr(0, index));
		temp = temp.substr(index+1, temp.length()-1-index);
		cout << temp << "\n";
	}
	for (vector<string>::const_iterator i = thisDonors.begin(); i != thisDonors.end(); ++i) cout << *i << "\n";

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

	cout << onlylast.substr(0, onlylast.begin()-onlylast.end()-1) << "\n" << both.substr(0, both.begin()-both.end()-1) << "\n";

	for (int i = 0; i < thisDonors.size(); i++) {
		onlythis += thisDonors[i] + ",";
	}

	cout << onlythis.substr(0, onlythis.begin()-onlythis.end()-1) << "\n";
	cout << "Done\n";
}
