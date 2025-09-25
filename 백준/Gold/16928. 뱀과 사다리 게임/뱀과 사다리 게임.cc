#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int cnt1, cnt2;
    cin >> cnt1 >> cnt2;
    vector<pair<int,int>> up;
    for (int i = 0; i < cnt1; i++) {
        int s, e;
        cin >> s >> e;
        up.push_back({s, e});
    }

    vector<pair<int,int>> down;
    for (int i = 0; i < cnt2; i++) {
        int s, e;
        cin >> s >> e;
        down.push_back({s, e});
    }

    vector<int> dist(101, 0);
    queue<int> q;
    q.push(1);

    while(!q.empty()) {
        int curr = q.front(); q.pop();
        for (int i = 1; i <= 6; i++) {
            int next = curr+i;
            bool found = false;
            for (int j = 0; j< up.size(); j++) {
                if (next == up[j].first) {
                    next = up[j].second;
                    found = true;
                    break;
                }
            }
            if (!found) {
                for (int j = 0; j < down.size(); j++) {
                    if (next == down[j].first) {
                        next = down[j].second;
                        break;
                    }
                }
            }
            if (next > 100) continue;
            if (dist[next] > 0) continue;
            dist[next] = dist[curr] + 1;
            q.push(next);
        }
    }

    cout << dist[100];
}