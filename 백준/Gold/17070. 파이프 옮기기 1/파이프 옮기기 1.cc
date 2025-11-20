#include <iostream>
#include<vector>
using namespace std;

struct Pipe
{
    int cnt;
    int h;
    int v;
    int c;
};


int main() {
    int n;
    cin >> n;
    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    vector<vector<Pipe>> dp(n, vector<Pipe>(n, {0, 0, 0, 0}));
    dp[0][1] = {1, 1, 0, 0};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) continue;
            if (i > 0 && arr[i-1][j] == 0) {
                if (dp[i-1][j].v || dp[i-1][j].c) {
                    dp[i][j].cnt += dp[i-1][j].v + dp[i-1][j].c;
                    dp[i][j].v += dp[i-1][j].v + dp[i-1][j].c;
                }
            }
            if (j > 0 && arr[i][j-1] == 0) {
                if (dp[i][j-1].h || dp[i][j-1].c) {
                    dp[i][j].cnt += dp[i][j-1].c + dp[i][j-1].h;
                    dp[i][j].h = dp[i][j-1].c + dp[i][j-1].h;
                }
            }
            if (j > 0 && i > 0 && arr[i-1][j] == 0 && arr[i-1][j-1] == 0 && arr[i][j-1] == 0) {
                dp[i][j].cnt += dp[i-1][j-1].cnt;
                dp[i][j].c += dp[i-1][j-1].cnt;
            }
        }
    }

    cout << dp[n-1][n-1].cnt;
}