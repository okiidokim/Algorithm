#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, -1));
    int sx, sy;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            if (num == 0) board[i][j] = num;
            if (num == 2) {
                sx = i;
                sy = j;
                board[i][j] = num;
            }
        }
    }
    
    vector<vector<bool>> vis(n, vector<bool>(m,false));
    queue<pair<int,int>> q;
    q.push({sx, sy});
    board[sx][sy] = 0;

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    
    while (!q.empty()) {
        auto [x, y] = q.front();q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (board[nx][ny] != -1) continue;
            q.push({nx, ny});
            board[nx][ny] = board[x][y]+1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}