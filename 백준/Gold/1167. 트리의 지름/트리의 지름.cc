// 11:42 ~ 13:15
// 1차 : 시간 초과 샤갈샤갈 (그래도 로직은 풀었다는 거에 만족...) - 저거 dfs v번 만큼 돌면 안 되긴 해...
// 2차 : 13:25 ~ 13:41

#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int v;
vector<int> dist(100001);
vector<vector<pair<int,int>>> tree(100001);
int answer;

void dfs(int s, int curr) {
    for (int i = 0; i < tree[curr].size(); i++) {
        auto [next, d] = tree[curr][i];
        if (dist[next] != 0 && dist[next] <= d + dist[curr]) continue;
        if (s == next) continue;
        dist[next] = d + dist[curr];
        dfs(s, next);
    }
}

int main() {
    cin >> v;
    for (int i = 0; i < v+1; i++) dist[i] = 0;

    for (int i = 0; i < v; i++) {
        int start;
        cin >> start;
        while (1) {
            int x, d;
            cin >> x;
            if (x == -1) break;
            cin >> d;
            tree[start].push_back({x, d});
        }
    }
 
    dfs(1, 1);
    int s = 0;
    int answer = 0;
    for (int i = 1; i < v+1; i++) {
        if (answer < dist[i]) {
            answer = dist[i];
            s = i;
        }
        dist[i] = 0;
    }

    dfs(s, s);
    for (int i = 1; i < v+1; i++) {
        answer = max(answer, dist[i]);
    }
    cout << answer;
}