//21:20 ~ 21:54 (35분)
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

char arr[20][20];
vector<bool> alpha(26, false);
vector<vector<bool>> vis(20, vector<bool>(20, false));
int answer;
int r, c;

void dfs(int x, int y, int depth) {
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int curr = arr[x][y];

    if (x < 0 || y < 0 || x > r-1 || y > c-1) return;
    if (vis[x][y]) return;
    if (alpha[curr]) return;
    
    answer = max(depth, answer);
    vis[x][y] = true;
    alpha[curr] = true;
    
    for (int i = 0; i < 4; i++) {
        int nx = dx[i] + x;
        int ny = dy[i] + y;
        int next = arr[nx][ny];
        dfs(nx, ny, depth+1);
    }

    vis[x][y] = false;
    alpha[curr] = false;
}

int main() {
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0,0,1);
    cout << answer;
}