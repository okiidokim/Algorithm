//12:46 ~ 14:27 (100분;;;)샤갈샤갈 문제 이해 잘못함;;
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
    int n, m, s, e;
    vector<vector<pair<int,int>>> v(1001);
    
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int s, e, w;
        cin >> s >> e >> w;
        v[s].push_back({e, w});
    }
    cin >> s >> e;

    vector<int> par(1001, -1);
    vector<int> dist(1001, INT_MAX);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, s});
    dist[s] = 0;

    while (!q.empty()) {
        auto [cw, curr] = q.top(); q.pop();
        if (cw > dist[curr]) continue;
        for (int i = 0; i < v[curr].size(); i++) {
            auto [next, nw] = v[curr][i];
            if (cw + nw >= dist[next]) continue;
            q.push({cw + nw, next});
            par[next] = curr;
            dist[next] = cw + nw;
        }
    }

    vector<int> way;
    int curr = e;
    while (curr != -1) {
        way.push_back(curr);
        curr = par[curr];
    }
    reverse(way.begin(), way.end());

    cout << dist[e] << "\n" << way.size() << "\n";
    for (int n : way) {
        cout << n << " ";
    }
}