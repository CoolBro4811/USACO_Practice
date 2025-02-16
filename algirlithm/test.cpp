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

    vector<vector<vector<pair<int, int>>>> parent(n, vector<vector<pair<int, int>>>(n, vector<pair<int, int>>(5, {-1, -1})));

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
                        if (dp[i-1][j][k] > 0) {
                            parent[i][j][k+1] = {i-1, j};
                        }
                    }
                }

                if (j > 0) {
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k]) % MOD;
                    if (field[i][j] == target[k]) {
                        dp[i][j][k+1] = (dp[i][j][k+1] + dp[i][j-1][k]) % MOD;
                        if (dp[i][j-1][k] > 0) {
                            parent[i][j][k+1] = {i, j-1};
                        }
                    }
                }
            }
        }
    }

    cout << dp[n-1][n-1][4] << "\n";

    if (dp[n-1][n-1][4] > 0) {
        vector<pair<int, int>> path;
        int i = n - 1, j = n - 1, k = 4;
        while (k > 0) {
            path.push_back({i, j});
            auto [prev_i, prev_j] = parent[i][j][k];
            if (prev_i == -1 || prev_j == -1) {
                cout << "No valid path found.\n";
                return 0;
            }
            i = prev_i;
            j = prev_j;
            k--;
        }

        path.push_back({0, 0});  //starting point

        reverse(path.begin(), path.end());

        cout << "Path: ";
        for (auto [x, y] : path) {
            cout << "(" << x << ", " << y << ") ";
        }
        cout << "\n";
    }

    return 0;
}

