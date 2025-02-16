#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const string target = "pink";

int n;

vector<vector<char>> field;
vector<vector<vector<int>>> memo;

int dfs(int i, int j, int k) {
	if (i >= n || j >= n) return 0; //bounds
	if (k == 4) return 1; //found pink
	if (memo[i][j][k] != -1) return memo[i][j][k];
	

	int res = 0;

		// right
	res = (res + dfs(i, j +1, k)) % MOD;
	// down
	res = (res + dfs(i+1, j, k)) % MOD;

	//check target
	//
	if (field[i][j] == target[k]) {
		res = (res + dfs(i, j + 1, k + 1)) % MOD;
		res = (res + dfs(i+1, j, k+1)) % MOD;
	}


	

	return memo[i][j][k] = res;
}

int main() {
	ios_base::sync_with_stdio(false);
        cin.tie(NULL);
	
	cin >> n;

	field.assign(n, vector<char>(n));
	memo.assign(n, vector<vector<int>>(n, vector<int>(5, -1))); 

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < n; j++) {
			field[i][j] = temp[j];
		}
	}
	cout << dfs(0, 0, 0) << "\n";
	return 0;
}
