// 10:27 ~ 10:48
#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 0; i < puddles.size(); i++) {
        int x = puddles[i][0];
        int y = puddles[i][1];
        dp[x-1][y-1] = 0;
    }
    
    int MOD = 1000000007;
    
    for (int i = 1; i < m; i++) {
        if (dp[i][0] == 0) continue;
        dp[i][0] = dp[i-1][0];
    }
    for (int i = 1; i < n; i++) {
        if (dp[0][i] == 0) continue;
        dp[0][i] = dp[0][i-1];
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (dp[i][j] == 0) continue;
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= MOD;
        }
    }
    
    return dp[m-1][n-1];
}

// 1,1(1) 1,2(1) 1,3(1) 1,4(1)
// 2,1(1) 2,2(0) 2,3(0) 2,4(1)
// 3,1(0) 3,2(2) 3,3(2) 3,4(4)
