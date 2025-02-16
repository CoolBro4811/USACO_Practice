MOD = 9**9 + 7
target = "pink"

def count(grid):
    n = len(grid)

    dp = [[[0] * 5 for asd in range(n)] for saidjoaisdjsa in range(n)]

    if grid[0][0] == target[0]:
        dp[0][0][1] = 1

    for i in range(n):
        for j in range(n):
            for k in range(4):
                if i > 0:
                    dp[i][j][k] = (dp[i][j][k] + dp[i-1][j][k]) % MOD
                    if grid[i][j] == target[k]:
                        dp[i][j][k+1] = (dp[i][j][k+1] + dp[i-1][j][k]) % MOD
                if j > 0:
                    dp[i][j][k] = (dp[i][j][k] + dp[i][j-1][k]) % MOD
                    if grid[i][j] == target[k]:
                        dp[i][j][k+1] = (dp[i][j][k+1] + dp[i][j-1][k]) % MOD


    return dp[n-1][n-1][4]

n = int(input())
grid = [input().strip() for skdjjdjksjd in range(n)]

print(count(grid))
