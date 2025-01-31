#include <bits/stdc++.h>
using namespace std;

struct Player {
	pair<int, int> pos;

	bool update(vector<pair<int, int>> &obstacles, char &input, int &width) {
		this->pos.first = input == ' ' ? this->pos.first : input == 'L' ? this->pos.first - (this->pos.first - 1 > 0 ? 1 : 0) : this->pos.first + (this->pos.first + 1 < width ? 1 : 0);
		if (find(obstacles.begin(), obstacles.end(), this->pos) != obstacles.end()) { this->pos.second++; return true; }
		return false;
	}
	Player(int x, int y) {
	this->pos = pair<int, int>(x, y);
	};
};



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

void addString(char *&c, char &a, int &times) {
	for (int i = 0; i < times; i++) {
		c += a;
	}
	return;
}

void getOutput() {
	int w, l, s;
	cin >> w >> l >> s;
	w--;
	s--;
	// fix how i coded it
	
	Player player = Player(s, 0);

	vector<pair<int,int>> obstacles;

	int numObstacles;
	cin >> numObstacles;

	for (int i = 0; i < 0; i++) {
		int x, y;
		cin >> x >> y;
		obstacles.emplace_back(x, y);
	}

	char *map;

	cout << map;
	return;
}

