#include<iostream>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    int table[n][n];
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> table[i][j];
        }
        dp[i][0] = table[i][0];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i][j-1] + table[i][j];
        }
    }
    while (m--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int answer = 0;
        for (int i = x1-1; i < x2; i++) {
            if (y1 == 1) answer += dp[i][y2-1];
            else answer += dp[i][y2-1] - dp[i][y1-2];
        }
        cout << answer << "\n";
    }
}