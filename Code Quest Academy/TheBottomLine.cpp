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
    int x, y;
    cin >> x >> y;

    if (x > y) {
        cout << "Cassowary Craft sold " << (x-y) << " more aircraft\n";
    }
    else if (x < y) {
        cout << "Lead Balloons Ltd sold "<< (y-x) << " more aircraft\n";
    }
    else {
        cout << "Cassowary Craft and Lead Balloons Ltd sold the same number of aircraft\n";
    }
    return;
}

