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
    double ix, iy, dx, x, y;
    cin >> iter >> ix >> iy >> dx >> x >> y;

    int i = 0;
    double dy = ix*x + iy*y;
    double prev = iy;
    double curr = prev;

    while (i < iter) {
        cout << dy << " << y'(" << (i*dx) << ", " << (prev) << ")\n";
        
        curr = dy*dx + prev;
        cout << curr << " << " << dy << "(" << dx << ")" << " + " << prev << "\n";
        
        dy = x*(i+1)*dx + y*curr;
        prev = curr;
        i++;
    }
    
}

