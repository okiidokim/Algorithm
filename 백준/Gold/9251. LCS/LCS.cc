//12:04 ~ 12:47 (43분)
#include<iostream>
#include<vector>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    s1 = '0' + s1;
    s2 = '0' + s2;
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    cout << dp[n-1][m-1];
}