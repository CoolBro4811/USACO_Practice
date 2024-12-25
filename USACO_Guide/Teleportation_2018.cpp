#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    ifstream input("./teleport.in");
    ofstream output("./teleport.out");

	int x, y, xt, yt;
    input >> x >> y >> xt >> yt;
    int dx = min(abs(y-x), abs(xt-x) < abs(yt-x) ? abs(xt-x) + abs(yt-y) : abs(xt-y) + abs(yt-x));
    output << dx;

	return 0;
}

