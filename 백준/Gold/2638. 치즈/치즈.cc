// 1차 : 11:44 ~ 12:27 (43분)
// 가운데 구멍 있는 경우 제외 구현 완료

// 2차 - 구멍 있는 경우 구해야 됨

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    
    vector<vector<bool>> isAir(n, vector<bool>(m, false));
    queue<pair<int, int>> aq;
    aq.push({0,0});
    isAir[0][0] = true;
    while (!aq.empty()) {
        auto [x, y] = aq.front(); aq.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
            if (arr[nx][ny] == 1) continue;
            if (isAir[nx][ny]) continue;
            isAir[nx][ny] = true;
            aq.push({nx, ny});
        }
    }
    

    for (int i = 1; i < n-1; i++) {
        for (int j = 1; j < m-1; j++) {
            if (arr[i][j] == 0) continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                if (isAir[i+dx[k]][j+dy[k]]) cnt++;
                if (cnt == 2) break;
            }
            if (cnt == 2 && !vis[i][j]) {
                q.push({i, j});
                vis[i][j] = true;
            }
        }
    }

    int answer = 0;
    while (!q.empty()) {
        int size = q.size();
        while(size--) {
            auto [x, y] = q.front(); q.pop();

            int cnt = 0;
            for (int i = 0; i < 4; i++) {
                if (isAir[x+dx[i]][y+dy[i]]) cnt++;
                if (cnt == 2) break;
            }
            if (cnt < 2) {
                q.push({x, y});
                continue;
            }

            arr[x][y] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                isAir[i][j] = false;
            }
        }
        aq.push({0,0});
        isAir[0][0] = true;
        while (!aq.empty()) {
            auto [x, y] = aq.front(); aq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx > n-1 || ny > m-1) continue;
                if (arr[nx][ny] == 1) continue;
                if (isAir[nx][ny]) continue;
                isAir[nx][ny] = true;
                aq.push({nx, ny});
            }
        }
        for (int i = 1; i < n-1; i++) {
            for (int j = 1; j < m-1; j++) {
                if (arr[i][j] == 0) continue;
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    if (isAir[i+dx[k]][j+dy[k]]) cnt++;
                    if (cnt == 2) break;
                }
                if (cnt == 2 && !vis[i][j]) {
                    q.push({i, j});
                    vis[i][j] = true;
                }
            }
        }


        answer++;  
    }
    cout << answer;
}