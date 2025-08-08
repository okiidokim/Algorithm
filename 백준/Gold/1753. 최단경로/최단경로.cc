#include<iostream>
#include<queue>
#include<vector>
#define INF 4000000
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    int v, e, k;
    cin >> v >> e;
    cin >> k;
    
	int d[v+1];
    vector<pair<int,int>> vec[v+1];
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        vec[a].push_back({c,b});
    }
    for (int i = 0; i < v+1; i++)
		d[i] = INF;
	
	d[k] = 0;
    q.push({0,k}); //시작점 삽입
    
    while (!q.empty()) {
        int w = q.top().first;
        int vt = q.top().second;
		q.pop();
		if (d[vt] < w) continue;
        for (int i = 0; i < vec[vt].size(); i++) {
            int w1 = vec[vt].at(i).first;
            int next = vec[vt].at(i).second;
            int w2 = w + w1;
            if (w2 < d[next]) {
                d[next] = w2;
                q.push({w2, next});
            }
        }
    }
    
    for (int i = 1; i < v+1; i++) {
        if (d[i] == INF) cout << "INF\n";
        else cout << d[i] << "\n";
    }
}