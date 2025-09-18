#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int dx[3] = {2, 1, -1};
    vector<int> vis(100001, INT_MAX);
    queue<int> q;
    q.push(n);
    vis[n] = 0;
    while(!q.empty()) {
        int curr = q.front(); q.pop();
        if (curr == k) break;
        for (int i = 0; i < 3; i++) {
            int next = curr;
            if (i == 0) next *= dx[i];
            else next += dx[i]*1;
            if (next < 0 || next > 100000) continue;
            if (vis[next] < INT_MAX) continue;
            vis[next] = min(vis[curr]+1, vis[next]);
            q.push(next);
        }
    }
    cout << vis[k];
}