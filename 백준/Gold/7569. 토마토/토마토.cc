#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Box
{
    int x;
    int y;
    int z;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, h;
    cin >> n >> m >> h;
    int tmt[h][m][n];

    int zeros = 0;
    queue<Box> q;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                cin >> tmt[i][j][k];
                if (tmt[i][j][k] == 0) zeros++;
                if (tmt[i][j][k] == 1) q.push({j, k, i});
            }
        }
    }

    if (zeros == 0) {
        cout << 0;
        return 0;
    }

    int dx[6] = {1, -1, 0, 0, 0, 0};
    int dy[6] = {0, 0, 1, -1, 0, 0};
    int dz[6] = {0, 0, 0, 0, 1, -1};
    
    while (!q.empty()) {
        Box curr = q.front(); q.pop();
        for (int i =0; i < 6; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            int nz = curr.z + dz[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= m || ny >= n || nz >= h) continue;
            if (tmt[nz][nx][ny] != 0) continue;
            q.push({nx, ny, nz});
            tmt[nz][nx][ny] = tmt[curr.z][curr.x][curr.y] + 1;
        }
    }

    int answer = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < n; k++) {
                if (tmt[i][j][k] == 0) {
                    cout << -1;
                    return 0;
                }
                answer = max(answer, tmt[i][j][k]);
            }
        }
    }

    cout << answer-1;
}