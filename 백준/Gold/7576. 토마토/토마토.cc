#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> tmt(m, vector<int> (n,0));
    queue<pair<int,int>> q;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmt[i][j];
            if (tmt[i][j] == 1) q.push({i, j});
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= m || ny >= n) continue;
            if (tmt[nx][ny] > 0 || tmt[nx][ny] == -1) continue;
            tmt[nx][ny] = tmt[x][y]+1;
            q.push({nx, ny});
        }
    }

    int answer = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (tmt[i][j] == 0) {
                cout << -1;
                return 0;
            }
            answer = max(answer, tmt[i][j]);
        }
    }

    cout << answer-1;
}