#include<iostream>
using namespace std;

int n, m;
int arr[101][101];
bool visited[101][101];
int cnt;
int tmp;

void dfs(int x, int y){
    if (x < 0 || y < 0) return;
    if (x > n-1 || y > m-1) return;
    if (visited[x][y]) return;
    if (arr[x][y] == 0) return;
    visited[x][y] = true;
    tmp++;
    dfs(x+1, y);
    dfs(x, y+1);
    dfs(x-1, y);
    dfs(x, y-1);
}

int main() {
    int k;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int r,c;
        cin >> r >> c;
        arr[r-1][c-1] = 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j]) continue;
            tmp = 0;
            dfs(i,j);
            if (tmp > cnt) cnt = tmp;
        }
    }
    cout << cnt;
}