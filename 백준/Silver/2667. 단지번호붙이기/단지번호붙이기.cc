#include<iostream>
#include<queue>
#include<vector>
using namespace std;

char loc[26][26];
bool visited[26][26];
int cnt = 0;
int n = 5;

void dfs(int x, int y) {
    if (loc[x][y] == '0') return;
    if (visited[x][y]) return;
    visited[x][y] = true;
	cnt++;
	if (x < n-1) dfs(x+1, y);
	if (x > 0) dfs(x-1, y);
	if (y < n-1) dfs(x, y+1);
	if (y > 0) dfs(x, y-1);
}

int main() {
    cin >> n;
    priority_queue<int,vector<int>,greater<int>> pq;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> loc[i][j];
		}
	}
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
			if (loc[i][j] == '0') continue;
            cnt = 0;
            dfs(i,j);
			if (cnt != 0)
				pq.push(cnt);
        }
    }
	cout << pq.size() << "\n";
    while(!pq.empty()) {
        cout << pq.top() <<"\n";
        pq.pop();
    }
}