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
	double burnX = 0;
	double burnY = 0;
	for (int i = 0; i < cubes; i++) {
		int xf, yf;
		double time;
		cin >> xf >> yf >> time;

		double dx = (xf-xi)/2;
		double dy = (yf-yi)/2;
		time /= 2.0;

		// -0.5t^2 + ti*t - dx
		// t + sqrt(t^2 + 2*dx) /	
		const double a = 1.0;

		burnX += 2*(time - sqrt(pow(time, 2) - 2*dx));
		burnY += 2*(time - sqrt(pow(time, 2) - 2*dy)); 

		// cout << ((2*time - sqrt(pow(time, 2) - 2*dy) - sqrt(pow(time, 2) - 2*dx))*2) << "\n";
		
		printf("time: %f\nxi %d, xf, %d, yi, %d, yf %d\nburnX: %lf\nburnY: %lf\n", time, xi, xf, yi, yf, burnX, burnY);
		
		xi = xf;
		yi = yf;
	}
	cout << (burnX + burnY) << "\n";
}

