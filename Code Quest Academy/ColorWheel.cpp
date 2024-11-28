#include <string>
#include <bits/stdc++.h>
using namespace std;

void getOutput(unordered_map<string, string> colors);

int main() {
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	
	int n;
	cin >> n;
	cin.ignore();

	unordered_map<string, string> colors;

	colors["red-orange"] = "red and yellow";
	colors["orange"] = "red and yellow";
	colors["yellow-orange"] = "red and yellow";

	colors["red-violet"] = "blue and red";
	colors["violet"] = "blue and red";
	colors["blue-violet"] = "blue and red";

	colors["yellow-green"] = "blue and yellow";
	colors["green"] = "blue and yellow";
	colors["blue-green"] = "blue and yellow";


	for (int i = 0; i < n; i++) {
		getOutput(colors);
	}

	return 0;
}

void getOutput(unordered_map<string, string> colors) {
	string color;
	cin >> color;
	

	if (colors.find(color) == colors.end()) {
		cout << "No colors need to be mixed to make " << color << ".\n";
		return;
	}
	cout << "In order to make " << color << ", " << colors[color] << " must be mixed.\n";
}

