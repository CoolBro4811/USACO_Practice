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

string formatNumber(double num);

void getOutput() {
	double x, y, z;
	cin >> x >> y >> z;

	x = fmod((x-180), 360);
	x = x > 0 ? x : 360 + x;
	y = fmod((y-180), 360);
	y = y > 0 ? y : 360 + y;
	z = fmod((z-180), 360);
	z = z > 0 ? z : 360 + z;

	cout << formatNumber(x) << formatNumber(y) << formatNumber(z) << "\n";
}

string formatNumber(double num) {
	num = num == 360 ? 0 : num;
    	ostringstream oss;
    	oss << fixed << setprecision(2) << setfill('0') << setw(6) << num;
    	string formatted = oss.str();

	size_t dotPos = formatted.find('.');
    	while (dotPos < 3) {
        	formatted.insert(0, "0");
        	dotPos++;
    	}

	formatted.push_back(' ');
	return formatted;
}
