//12:21 ~ 13:07 (46분)
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

vector<int> edges;
vector<vector<pair<int,int>>> v(100);
vector<int> dist(100);
int n, m, r;

void dfs(int curr) {
    for (int i = 0; i < v[curr].size(); i++) {
        auto [next, l] = v[curr][i];
        if (dist[curr] + l > m) continue;
        if (dist[next] <= dist[curr] + l) continue;

        dist[next] = dist[curr] + l;
        dfs(next);
    }
}

int main() {
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++) {
        int items;
        cin >> items;
        edges.push_back(items);
    }
    for (int i = 0; i < r; i++) {
        int a, b, l;
        cin >> a >> b >> l;
        v[a-1].push_back({b-1, l});
        v[b-1].push_back({a-1, l});
    }
    int sum = 0, answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) dist[j] = INT_MAX;
        dist[i] = 0;
        dfs(i);
        for (int j = 0; j < n; j++) {
            if (dist[j] == INT_MAX) continue;
            sum += edges[j];
        }
        answer = max(sum, answer);
        sum = 0;
    }
    cout << answer;
}