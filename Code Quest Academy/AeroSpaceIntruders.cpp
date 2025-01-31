#include <bits/stdc++.h>
using namespace std;

void getOutput();

struct ship {
	char *name;
	int speed;
	int x;
	int y;

	ship(char *n, int s, int X, int Y) {
		this->name = n;
		this->speed = s;
		this->x = X;
		this->y = Y;
	}

	void updateLoc() {
		x += speed;
	}

	void printInformation() {
		cout << "Destroyed Ship: " << name << " xLoc: " << x << "\n";
	}
};

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
	int n;
	cin >> n;
	cin.ignore();

	vector<ship> ships;

	for (int i = 0; i < n; i++) {
		char *name, *type;
		int x, y;
		scanf("%s_%s:%d,%d", name, type, &x, &y);
		int speed = type[0] == 'A' ? 10 : type[0] == 'B' ? 20 : 30;
		ships.emplace_back(type, speed, x, y);
	}
	
	sort(ships.begin(), ships.end(), [](const ship &a, const ship &b) {
		return a.x < b.x;
	});

	for (int i = 0; i < ships.size(); i++) {
		ships[0].printInformation();
		ships.erase(ships.begin());
		
		for (auto &ship : ships) {
			ship.updateLoc();
		}

		sort(ships.begin(), ships.end(), [](const ship &a, const ship &b) {
        		return a.x < b.x;
    		});
	}
}

