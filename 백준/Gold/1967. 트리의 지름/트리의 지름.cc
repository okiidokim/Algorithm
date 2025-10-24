#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<vector<pair<int,int>>> g(10001);
vector<int> leaves;
vector<bool> vis(10001, false);
vector<bool> isLeaf(10001, false);
int answer;

void dfs(int start, int curr, int sum) {
    if (start != curr && isLeaf[curr]) {
        answer = max(sum, answer);
        return;
    }

    for (int i = 0; i < g[curr].size(); i++) {
        auto [next, w] = g[curr][i];
        if (vis[next]) continue;
        vis[next] = true;
        dfs(start, next, sum + w);
        vis[next] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < n-1; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            leaves.push_back(i);
            isLeaf[i] = true;
        }
    }

    for (int i = 0; i < leaves.size(); i++) {
        vis[leaves[i]] = true;
        dfs(leaves[i], leaves[i], 0);
        vis[leaves[i]] = false;
    }

    cout << answer;
}