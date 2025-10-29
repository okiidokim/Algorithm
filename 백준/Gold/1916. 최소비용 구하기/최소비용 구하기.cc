// 6:46 ~ 6:59 (13분)
// 1치 : 메모리초과 32%
#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> city(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        city[a].push_back({b,w});
    }
    int s, e;
    cin >> s >> e;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, s});
    vector<int> dist(n+1, INT_MAX);
    dist[s] = 0;

    while (!pq.empty()) {
        auto [w, curr] = pq.top(); pq.pop();
        if (dist[curr] != w) continue;
        if (curr == e) {
            cout << w;
            return 0;
        }
        for (int i = 0; i < city[curr].size(); i++) {
            auto [next, nw] = city[curr][i];
            if (nw + w < dist[next]) {
                pq.push({nw+w, next});
                dist[next] = nw + w;
            }
        }
    }
    return 0;
}