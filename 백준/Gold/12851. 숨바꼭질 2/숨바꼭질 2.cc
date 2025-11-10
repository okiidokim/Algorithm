// 20:00 ~ 
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    queue<int> q;
    q.push(n);

    vector<int> vis(100001, 0); //경우의 수
    vector<int> dist(100001, INT_MAX); //시간
    dist[n] = 0;
    vis[n] = 1;

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == k) continue;

        int next[3] = {curr-1, curr+1, curr*2};
        for (int i = 0; i < 3; i++) {
            int nextPoint = next[i];
            if (nextPoint < 0 || nextPoint > 100000) continue;
            if (dist[nextPoint] == INT_MAX) {
                q.push(nextPoint);
                vis[nextPoint] = vis[curr];
                dist[nextPoint] = dist[curr]+1;
            } else if (dist[nextPoint] == dist[curr]+1) {
                vis[nextPoint] += vis[curr];
            } 
        }
    }

    cout << dist[k] << "\n" << vis[k];
}