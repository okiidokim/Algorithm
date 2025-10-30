// 15:20 ~ 15:47 (30분)
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int n, m, x; //학생 번호, 길 수, 모임 위치
    cin >> n >> m >> x;

    vector<vector<int>> homes(n+1, vector<int> (n+1, INT_MAX));
    for (int i = 0; i < m; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        homes[a][b] = min(homes[a][b], t);
    }
    for (int i = 0; i < n+1; i++) {
        homes[i][i] = 0;
    }

    for (int k = 1; k < n+1; k++) { //중간
        for (int i = 1; i < n+1; i++) { //시작
            if (homes[i][k] == INT_MAX) continue;
            for (int j = 1; j < n+1; j++) { //끝
                if (homes[k][j] == INT_MAX) continue;
                int t = homes[i][k] + homes[k][j];
                homes[i][j] = min(homes[i][j], t);
            }
        }
    }

    int answer = 0;
    for (int i = 1; i < n+1; i++) {
        answer = max(homes[i][x] + homes[x][i], answer);
    }
    cout << answer;
}