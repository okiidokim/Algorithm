// 21:07 ~ 22:10 (약 1시간)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int n, m; //사람 수, 파티 수
bool knows[51]; //아는 사람 flag
int parent[51];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
	u = find(u);
	v = find(v);
	if (u == v) return;
	parent[u] = v;
}

int main() {
    for (int i = 0; i < 51; i++) parent[i] = i;
    
    cin >> n >> m;
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int who;
        cin >> who;
        knows[who] = true;
    }

    vector<vector<int>> parties(m);
    for (int i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int hum;
            cin >> hum;
            parties[i].push_back(hum);
            merge(parties[i][0], parties[i][j]);
        }
    }

    for (int i = 1; i < n+1; i++) {
        int p = find(i);
        if (knows[i]) knows[p] = true;
    }

    int answer = 0;
    for (int i = 0; i < m; i++) {
        bool able = true;
        for (int who : parties[i]) {
            if (knows[find(who)]) {
                able = false;
                break;
            }
        }
        if (able) answer++;
    }
    cout << answer;
}