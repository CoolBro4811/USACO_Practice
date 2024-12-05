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
	double x, y;
	cin >> x >> y;
	x = x*1000000.0;
	y = y/3600.0;

	int time = round(x/y);

	int days = time / 86400;//24*60^2
	time -= days*86400;

	int hours = floor(time/3600);
	time -= hours*3600;
	
	int mins = floor(time/60);
	time -= mins*60;

	int secs = floor(time);

	printf("Time to Mars: %d days, %d hours, %d minutes, %d seconds\n", days, hours, mins, secs);
}

