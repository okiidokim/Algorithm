#include<iostream>
using namespace std;

int board[101][101];
long long dp[101][101];
int n;

long long dfs(int x, int y) {
    if (x > n-1 || y > n-1) return 0;
	if (x == n-1 && y == n-1) return 1;

    if (dp[x][y] != -1) return dp[x][y];
    
    dp[x][y] = 0;
	
	if (board[x][y] == 0) return 0;
    dp[x][y] += dfs(x, y+board[x][y]);
    dp[x][y] += dfs(x+board[x][y], y);
	return dp[x][y];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            dp[i][j] = -1;
        }
    }
    
    cout << dfs(0,0);
}