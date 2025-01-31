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

void printPair(pair<double, double> &a) {
	cout << fixed << setprecision(2) << round(a.first*100)/100 << "," << round(a.second*100)/100;
	return;
}

void getOutput() {
	int x, y, p, r1, r2;

	cin >> x >> y >> p >> r1 >> r2;

	vector<pair<double, double>> points;

	for (int i = 0; i < p; i++) {
		double angle_outer = 2*M_PI/p*i + M_PI/2;
		double angle_inner = 2*M_PI/(2*p) + 2*M_PI*i/p + M_PI/2;

		points.emplace_back(r1*cos(angle_outer) + x, r1*sin(angle_outer) + y);
		points.emplace_back(r2*cos(angle_inner) + x, r2*sin(angle_inner) + y);
	}

	for (int i = 0; i < points.size(); i++) {
		printPair(points[i]);
		if (i < points.size()-1) cout << "=";
		else cout << "\n";
	}
	return;
}

