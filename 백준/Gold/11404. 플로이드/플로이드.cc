// 15:30 ~ 
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cost(n+1, vector<int>(n+1, INT_MAX));
    for (int i = 1; i < n+1; i++) {
        cost[i][i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        cost[a][b] = min(cost[a][b], w);
    }
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if (cost[j][i] == INT_MAX) continue;
            for (int k = 1; k < n+1; k++) {
                if (cost[i][k] == INT_MAX) continue;
                int through = cost[j][i] + cost[i][k];
                if (through < cost[j][k]) cost[j][k] = through;
            }

        }
    }
    for (int i = 1; i < n+1; i++) {
        for (int j = 1; j < n+1; j++) {
            if (cost[i][j] == INT_MAX) cout << 0 << " ";
            else cout << cost[i][j] << " ";
        }
        cout << "\n";
    }
}