#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int> arr[1000];
bool visited[1000];
queue<int> q;

void dfs(int x) {
    if (visited[x-1] == true) return;
    visited[x-1] = true;
    cout << x << " ";
    for (int i = 0; i < arr[x-1].size(); i++) {
        dfs(arr[x-1].at(i));
    }
}

void bfs(int x) {
    q.push(x);
    while(q.empty() == false) {
        int a = q.front(); q.pop();
        if (visited[a-1] == true) continue;
        visited[a-1] = true;
        cout << a << " ";
        for (int i = 0; i < arr[a-1].size(); i++) {
            q.push(arr[a-1].at(i));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n, m, v;
    cin >> n >> m >> v;
    
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a-1].push_back(b);
        arr[b-1].push_back(a);
    }
    
    for (int i =0; i < n; i++) {
        sort(arr[i].begin(), arr[i].end());
    }
    
    dfs(v);
    cout << "\n";
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    bfs(v);
    cout << "\n";
}