#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int,int>> thing;
    vector<int> dp(k+1, 0);
    for (int i = 0; i < n; i++) {
        int w, v;
        cin >> w >> v;
        thing.push_back({w, v});
    }
    for (auto &it : thing) {
        auto [w, v] = it;
        for (int j = k; j >= w; --j) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    cout << dp[k];
}