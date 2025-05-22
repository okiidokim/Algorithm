#include<iostream>
#include<vector>
using namespace std;

int n, m, cnt;
vector<int> vec[110];
bool vis[110];

void dfs(int x) {
    if (vis[x] == true) return;
    vis[x] = true;
    cnt++;
    for (int i = 0; i < vec[x].size(); i++) {
        dfs(vec[x].at(i));
    }
}

int main() {
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    dfs(1);
    cout << cnt - 1<< "\n";
}