#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
const string target = "pink";

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<char>> field(n, vector<char>(n));
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;

		for (int j = 0; j < n; j++) {
			field[i][j] = temp[j];
		}
	}

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(5, 0)));

	if (field[0][0] == target[0]) {
		dp[0][0][1] = 1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				if (i > 0) {
					dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]) % MOD;
					if (field[i][j] == target[k]) {
						dp[i][j][k+1] = (dp[i][j][k+1] + dp[i-1][j][k]) % MOD;
					}
				}

				if (j > 0) {
					dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k]) % MOD;
					if (field[i][j] == target[k]) {
						dp[i][j][k+1] = (dp[i][j][k+1] + dp[i][j-1][k]) % MOD;
					}
				}
			}
		}
	}
	cout << dp[n-1][n-1][4] << "\n";
	return 0;
}
