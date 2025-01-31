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
	int n;
	cin >> n;

	vector<string> arr;

	for (int i = 0; i < n; i++) {
		string url;
		int kilobytes;
		cin >> url >> kilobytes;

		if (url.find("lmco.com")) {
			continue;
		}
		if (kilobytes > 1000) {
			arr.push_back(url + static_cast<string>(kilobytes));
		}


	}
}

