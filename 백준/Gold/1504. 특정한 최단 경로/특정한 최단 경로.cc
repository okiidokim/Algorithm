// 9:58 ~ 10:19 (약 20분)
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int n, e;

int bfs(int s, int e,  vector<vector<pair<int,int>>> graph) {
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    vector<int> dist(n+1, 0);
    pq.push({0, s});

    while (!pq.empty()) {
        auto [sum, p] = pq.top(); pq.pop();
        if (p == e) break;
        for (int i = 0; i < graph[p].size(); i++) {
            auto [np, w] = graph[p][i];
            if (dist[np] < sum+w && dist[np] != 0) continue;
            pq.push({sum+w, np});
            dist[np] = sum+w;
        }
    }

    return dist[e];
}

int main() {
    cin >> n >> e;
    if (e == 0) {
        cout << -1;
        return 0;
    }

    vector<vector<pair<int,int>>> graph(n+1);
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> a >> b>> w;
        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }

    int v1, v2;
    cin >> v1 >> v2;

    int v1tov2 = bfs(v1, v2, graph);
    if (v1tov2 == 0) {
        cout << -1;
        return 0;
    }

    if ((v1 == 1 && v2 == n) || (v1 == n && v2 == 1)) {
        cout << v1tov2;
        return 0;
    }

    int d1 = bfs(1, v1, graph);
    int d2 = bfs(v2, n, graph);
    int d3 = bfs(1, v2, graph);
    int d4 = bfs(v1, n, graph);

    if ((d1 == 0 || d2 == 0) && (d3 == 0 || d4 == 0)) {
        cout << -1;
        return 0;
    }

    cout << v1tov2 + min(d1 + d2, d3 + d4);

}