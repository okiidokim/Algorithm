#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int n, m;
char board[50][50];

int getBlackStart(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i+j)%2 == 0 && board[i+x][j+y] == 'W') cnt++;
            else if ((i+j)%2 == 1 && board[i+x][j+y] == 'B') cnt++;
        }
    }
    return cnt;
}
int getWhiteStart(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i+j)%2 == 0 && board[i+x][j+y] == 'B') cnt++;
            else if ((i+j)%2 == 1 && board[i+x][j+y] == 'W') cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    int answer = INT_MAX;

    for (int i = 0; i <= n-8; i++) {
        for (int j = 0; j <= m-8; j++) {
            int b = getBlackStart(i, j);
            int w = getWhiteStart(i, j);
            answer = min({answer, b, w});
        }
    }
    cout << answer;
}