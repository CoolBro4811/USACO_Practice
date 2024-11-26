#include <string>
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
	int speed;
	bool isBirthday;
	string birthday;

	cin >> speed >> birthday;

	isBirthday = birthday == "true";

	speed -= isBirthday ? 5 : 0;

	string no { "no ticket\n" };
	string big { "big ticket\n" };
	string small { "small ticket\n" };

	cout << (speed <= 60 ? no : speed <= 80 ? small : big);
}

