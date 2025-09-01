#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m>> k;
    int price[n+1]; price[0] = 0;
    for (int i = 1; i <= n; i++) cin >> price[i];
    vector<vector<int>> rel(n+1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a>> b;
        rel[a].push_back(b);
        rel[b].push_back(a);
    }

    int moneySum = 0;
    queue<int> q;
    vector<bool> vis(n+1, false);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        q.push(i);
        int currMoney = 10000000;
        while (!q.empty()) {
            int curr = q.front(); q.pop();
            if (vis[curr]) continue;
            vis[curr] = true;
            if (price[curr] < currMoney) currMoney = price[curr];
            for (int i = 0; i < rel[curr].size(); i++) {
                int next = rel[curr][i];
                if (price[next] < currMoney) currMoney = price[next];
                q.push(next);
            }
        }
        moneySum += currMoney;
    }
    if (moneySum <= k) cout << moneySum;
    else cout << "Oh no";
}