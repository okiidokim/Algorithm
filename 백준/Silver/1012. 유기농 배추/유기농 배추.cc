#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int t;
    cin >> t;

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    while(t--) {
        int n, m, b;
        cin >> n >> m >> b;

        vector<vector<int>> field(n, vector<int>(m, 0));
        for (int i = 0; i < b; i++) {
            int x, y;
            cin >> x >> y;
            field[x][y] = 1;
        }

        int answer = 0;
        queue<pair<int,int>> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] == 0) continue;
                if (vis[i][j]) continue;
                q.push({i, j});
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (int i = 0; i < 4; i++) {
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                        if (vis[nx][ny]) continue;
                        if (field[nx][ny] == 0) continue;
                        vis[nx][ny] = true;
                        q.push({nx, ny});

                    }
                }
                answer++;
            }
        }

        cout << answer << "\n";
    }
}