//9:52 ~ 11:18
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<climits>
using namespace std;

struct Way {
    int x;
    int y;
    int block;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    char mapp[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapp[i][j];
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<Way> pq;
    pq.push({0, 0, 1});
    vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(2, 0)));
    dist[0][0][1] = 1;

    while(!pq.empty()) {
        Way w = pq.front(); pq.pop();
        if (w.x == n-1 && w.y == m-1) {
            cout << dist[w.x][w.y][w.block];
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int nx = w.x + dx[i];
            int ny = w.y + dy[i];
            if (nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
            if (mapp[nx][ny] == '1' && w.block == 1) {
                pq.push({nx, ny, 0});
                dist[nx][ny][w.block-1] = dist[w.x][w.y][w.block]+1;
            } else if (mapp[nx][ny] == '0' && dist[nx][ny][w.block] == 0) {
                pq.push({nx, ny, w.block});
                dist[nx][ny][w.block] = dist[w.x][w.y][w.block]+1;
            }
        }
    }

    cout << -1;
}