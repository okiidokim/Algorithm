#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> campus(n, vector<char>(m, ' '));
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            campus[i][j]= c;
            if (c == 'I') q.push({i, j});
        }
    }

    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    int answer = 0;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (campus[nx][ny] == 'X') continue;
            if (campus[nx][ny] == 'P') answer++;
            campus[nx][ny] = 'X';
            q.push({nx, ny});
        }
    }
    if (answer == 0) cout << "TT";
    else cout << answer;
}