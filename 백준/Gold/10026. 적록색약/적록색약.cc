#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    char colors[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> colors[i][j];
        }
    }

    int threes = 0;
    int twos = 0;

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n, vector<bool>(n, false));

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            q.push({i, j});
            vis[i][j] = true;
            threes++;
            while(!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x +dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (vis[nx][ny]) continue;
                    if (colors[x][y] != colors[nx][ny]) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (colors[i][j] == 'R') colors[i][j] = 'G';
            vis[i][j] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j]) continue;
            q.push({i, j});
            vis[i][j] = true;
            twos++;
            while(!q.empty()) {
                auto [x, y] = q.front(); q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x +dx[i];
                    int ny = y + dy[i];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    if (vis[nx][ny]) continue;
                    if (colors[x][y] != colors[nx][ny]) continue;
                    vis[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }

    cout << threes << " " << twos;
}