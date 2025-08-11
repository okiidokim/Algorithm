// 8/11(월) 10:42 ~ 
// 다익스트라인 거까지 알겠음 BFS 가중치!

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n, m;
    cin >> n;
    cin >> m;
    vector<vector<pair<int,int>>> vec(n+1);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({b,c});
        vec[b].push_back({a,c});
    } //가중치 2차원 배열 완성

    vector<bool> visited(n+1, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,1});
    int sum = 0;
    int edgeCnt = 0;
    while (!pq.empty() && edgeCnt < n) {
        pair<int,int> curr = pq.top(); pq.pop(); //가중치, 다음 노드
        if (visited[curr.second]) continue;
        visited[curr.second] = true;
        sum += curr.first;
        edgeCnt++;
        for (int i = 0; i < vec[curr.second].size(); i++) {
            int next = vec[curr.second][i].first;
            int nextW = vec[curr.second][i].second;
            if (visited[next]) continue;
            pq.push({nextW, next});
        }
    }
    cout << sum;
}