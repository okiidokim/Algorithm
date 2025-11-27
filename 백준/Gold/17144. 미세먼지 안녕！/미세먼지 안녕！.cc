// 11:35 ~ 13:05 (90분)
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int r, c, time;
    cin >> r >> c >> time;
    vector<vector<int>> arr(r, vector<int>(c, 0));
    int cleanerX = 0; //x-1, x (다음 줄의 r) / y는 항상 1
    queue<pair<int,int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == -1) cleanerX = i;
            if (arr[i][j] > 4) q.push({i, j});
        }
    }

    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};
    while (time--) {
        vector<vector<int>> copy = arr;
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front(); q.pop();
            int amount = copy[x][y] / 5;
            int dirCnt = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx > r-1 || ny > c-1) continue;
                if (arr[nx][ny] == -1) continue;
                arr[nx][ny] += amount;
                dirCnt++;
            }
            arr[x][y] -= amount * dirCnt;
        }
        
        //청정기 밀기 - 거꾸로 앞에 거를 가져온다
        for (int i = cleanerX-2; i > 0; i--) {
            arr[i][0] = arr[i-1][0];
        }
        for (int i = 0; i < c-1; i++) {
            arr[0][i] = arr[0][i+1];
        }
        for (int i = 0; i < cleanerX-1; i++) {
            arr[i][c-1] = arr[i+1][c-1];
        }
        for (int i = c-1; i > 1; i--) {
            arr[cleanerX-1][i] = arr[cleanerX-1][i-1];
        }
        arr[cleanerX-1][1] = 0;

        for (int i = cleanerX + 1; i < r-1; i++) {
            arr[i][0] = arr[i+1][0];
        }
        for (int i = 0; i < c-1; i++) {
            arr[r-1][i] = arr[r-1][i+1];
        }
        for (int i = r-1; i > cleanerX; i--) {
            arr[i][c-1] = arr[i-1][c-1];
        }
        for (int i = c-1; i > 1; i--) {
            arr[cleanerX][i] = arr[cleanerX][i-1];
        }
        arr[cleanerX][1] = 0;

        while (!q.empty()) q.pop();
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (arr[i][j] > 4) q.push({i, j});
            }
        }

    }

    int answer = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == -1) continue;
            answer += arr[i][j];
        }
    }
    cout << answer;
}