// 16:00 ~ 16:30
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, m, w;
        cin >> n >> m >> w;
        vector<vector<int>> point(n+1, vector<int>(n+1, INT_MAX));
        for (int i = 0; i < m; i++) {
            int a, b, t;
            cin >> a >> b >> t;
            point[a][b] = min(t, point[a][b]);
            point[b][a] = min(t, point[b][a]);
        }
        for (int i = 0; i < w; i++) {
            int a, b, t;
            cin >> a >> b >> t;
            point[a][b] = min(t * (-1), point[a][b]);
        }

        for (int k = 1; k < n+1; k++) {
            for (int i = 1; i < n+1; i++) {
                if (point[i][k] == INT_MAX) continue;
                for (int j = 1; j < n+1; j++) {
                    if (point[k][j] == INT_MAX) continue;
                    int t = point[i][k] + point[k][j];
                    point[i][j] = min(t, point[i][j]);
                }
            }
        }

        // for (int i = 1; i < n+1; i++) {
        //     for (int j = 1; j < n+1; j++) {
        //         cout << point[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        bool flag = false;
        for (int i = 1; i < n+1; i++) {
            for (int j = 1; j < n+1; j++) {
                if (point[i][j] == INT_MAX) continue;
                if (point[j][i] == INT_MAX) continue;
                // cout << i << " " << j << " " << point[i][j] << " " << point[j][i] << "\n";
                if (point[i][j] + point[j][i] < 0) {
                    cout << "YES\n";
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (!flag) cout << "NO\n";
    }
}