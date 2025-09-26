#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int dx[19][4] = {
        {0, 1, 2, 3},
        {0, 0, 0, 0},
        {0, 1, 0, 1},
        {0, 0, 0, 1},
        {0, 1, 2, 2},
        {0, 1, 1, 1},
        {0, 0, 1, 2},
        {0, 0, 1, 1},
        {0, 1, 1, 2},
        {0, 1, 1, 2},
        {0, 0, 1, 0},
        {0, 1, 1, 2},
        {0, 1, 1, 1},
        {0, 1, 1, 1},
        {0, 1, 2, 2},
        {0, 0, 0, 1},
        {0, 0, 1, 2},
        {0, 0, -1, -1},
        {0, 1, 1, 2},
    };
    int dy[19][4] = {
        {0, 0, 0, 0},
        {0, 1, 2, 3},
        {0, 0, 1, 1},
        {0, 1, 2, 2},
        {0, 0, 0, -1},
        {0, 0, 1, 2},
        {0, 1, 0, 0},
        {0, 1, 1, 2},
        {0, 0, -1, -1},
        {0, 0, 1, 0},
        {0, 1, 1, 2},
        {0, 0, -1, 0},
        {0, 0, -1, 1},
        {0, 0, -1, -2},
        {0, 0, 0, 1},
        {0, 1, 2, 0},
        {0, 1, 1, 1},
        {0, 1, 1, 2},
        {0, 0, 1, 1},
    };

    int answer = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int a = 0; a < 19; a++) {
                int sum = 0;
                int flag = true;
                for (int b = 0; b < 4; b++) {
                    int nx = i + dx[a][b];
                    int ny = j + dy[a][b];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
                        flag = false;
                        break;
                    }
                    sum += arr[nx][ny];
                }
                if (flag) answer = max(answer, sum);
            }
        }
    }

    cout << answer;
}