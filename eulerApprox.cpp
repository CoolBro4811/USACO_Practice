#include <string>
#include <bits/stdc++.h>
using namespace std;
void getOutput();

int main() {
	std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	
	getOutput();

	return 0;
}

void getOutput() {
    int iter;
    double ix, iy, dx, x, xp, y, yp;
    cin >> iter >> ix >> iy >> dx >> x >> xp >> y >> yp;

    int i = 0;
    double dy = ix*pow(x, xp) + iy*pow(y, yp);
    double prev = iy;
    double curr = prev;

    while (i < iter) {
        cout << dy << " << y'(" << (i*dx) << ", " << (prev) << ")\n";
        
        curr = dy*pow(dx, xp) + prev;
        cout << curr << " << " << dy << "(" << dx << ")^" << xp << " + " << prev << "\n";
        
        dy = x*pow((i+1)*dx, xp) + y*pow(curr, yp);
        prev = curr;
        i++;
    }
    
}

