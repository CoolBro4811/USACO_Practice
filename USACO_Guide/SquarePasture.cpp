#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    ifstream input("./square.in");
    ofstream output("./square.out");

	int x1, y1, x2, y2, _x1, _y1, _x2, _y2;
    input >> x1 >> y1 >> x2 >> y2 >> _x1 >> _y1 >> _x2 >> _y2;

	int _dx = max(max(abs(_x2-x1), abs(_x2-_x1)), max(abs(x2-_x1), abs(x2-x1)));
	int _dy = max(max(abs(_y2-y1), abs(_y2-_y1)), max(abs(y2-_y1), abs(y2-y1)));

	double dx;
	dx = max(_dx, _dy);
	output << (dx*dx);

	return 0;
}

