#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m,'0'));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char num; cin >> num;
            board[i][j] = num;
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> dist(n, vector<int>(m,1));
    queue<pair<int,int>> q;
    q.push({0,0});
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] == '0') continue;
            board[nx][ny] = '0';
            dist[nx][ny] = dist[x][y] +1;
            q.push({nx, ny});
        }
    }
    cout << dist[n-1][m-1];
}