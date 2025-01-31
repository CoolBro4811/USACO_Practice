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

string YinOrYang(int yr) {
	if (yr % 2 == 0) {
		return "Yang";
	}
	return "Yin";
}

string Elements(int yr) {
	yr = ((yr - 4) % 10) / 2;
	string arr[] = {"Wood", "Fire", "Earth", "Metal", "Water"};

	return arr[yr];
}

string Animal(int yr) {
	string arr[] = {"Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"};
	yr = (yr - 4) % 12;

	return arr[yr];
}

void getOutput() {
	int yr;
	cin >> yr;

	cout << yr << " " << YinOrYang(yr) << " " << Elements(yr) << " " << Animal(yr) << "\n";
}

