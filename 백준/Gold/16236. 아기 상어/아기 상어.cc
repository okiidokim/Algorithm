// 15:45 ~ 17:05 (80분)
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Shark {
    int x;
    int y;
    int time;
};

int main() {
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    queue<Shark> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 9) {
                q.push({i, j, 0});
                vis[i][j] = true;
                arr[i][j] = 0;
            }
        }
    }

    vector<vector<int>> ate(n, vector<int>(n, 0));
    int shark = 2;
    int eatenCnt = 0;
    vector<Shark> fishes;
    while (!q.empty()) {
        auto [x, y, time] = q.front(); q.pop();
        if (fishes.size() > 0 && fishes[0].time == time) {
            int cx = 20, cy = 20;
            for (auto [fx, fy, ftime] : fishes) {
                cx = min(cx, fx);
            }
            for (auto [fx, fy, ftime] : fishes) {
                if (cx == fx) {
                    cy = min(cy, fy);
                }
            }
            eatenCnt++;
            arr[cx][cy] = 0;
            ate[cx][cy] = time;
            if (eatenCnt == shark) {
                shark++;
                eatenCnt = 0;
            }
            while (!q.empty()) q.pop();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    vis[i][j] = false;
                }
            }
            vis[cx][cy] = true;
            q.push({cx, cy, time});
            fishes.clear();
            continue;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > n-1 || ny > n-1) continue;
            if (vis[nx][ny]) continue;
            if (arr[nx][ny] > shark) continue;
            vis[nx][ny] = true;
            q.push({nx, ny, time+1});
            if (arr[nx][ny] < shark && arr[nx][ny] != 0) {
                fishes.push_back({nx, ny, time+1});
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            answer = max(answer, ate[i][j]);
        }
    }

    cout << answer;
}