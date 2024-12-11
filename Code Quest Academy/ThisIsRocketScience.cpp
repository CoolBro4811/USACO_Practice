#include <bits/stdc++.h>
using namespace std;

void getOutput(int cubes, int xi, int yi);

int main() {
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	
	int n;
	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {	
		int cubes, xi, yi;
		cin >> cubes >> xi >> yi;
		getOutput(cubes, xi, yi);
	}

	return 0;
}

void getOutput(int cubes, int xi, int yi) {
	// starting at xi, yi
	for (int i = 0; i < cubes; i++) {
		int xf, yf;
		double time;
		cin >> xf >> yf >> time;

		double dx = (xf-xi)/2.0;
		double dy = (yf-yi)/2.0;

		// -0.5t^2 + ti*t - dx
		// t + sqrt(t^2 + 2*dx) /	
		const double a = 1.0;

		cout << (time + sqrt(pow(time, 2) + 2*dx)) << "\n";
	}
}

