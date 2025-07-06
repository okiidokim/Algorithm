#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int power[n], joy[n];

    int init = 100;
    //세준이 처음 체력 : 100
    int dp[init] = {0};

    for (int i = 0; i < n; i++) {
        cin >> power[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> joy[i];
    }
    for (int i = 0; i < n; i++) {
        for (int p = init-1; p >= power[i]; p--) {
            dp[p] = dp[p] > (dp[p-power[i]] + joy[i]) ? dp[p] : dp[p-power[i]] + joy[i];
        }
    }
    int max = 0;
    for (int i = 1; i < 100; i++) {
        max = max > dp[i] ? max : dp[i];
    }
    cout << max;
}