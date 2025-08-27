#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int n;
    cin >> n;
    int seq[n*n];
    int rel[n*n + 1][4];
    for (int i = 0; i < n*n; i++) {
        cin >> seq[i];
        for (int j = 0; j< 4; j++) {
            cin >> rel[seq[i]][j];
        }
    }

    vector<vector<int>> desk(n, vector<int>(n, 0));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};
    
    for (int i = 0; i < n*n; i++) {
        int curr = seq[i];
        int newX = 0, newY = 0, max = -1, maxNears = -1;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (vis[j][k]) continue;
                int cnt = 0;
                int nears = 0;
                for (int d = 0; d < 4; d++) {
                    if (j + dx[d] < 0 || j + dx[d] >= n || k + dy[d] < 0 || k + dy[d] >= n) continue;
                    for (int n = 0; n < 4; n++) {
                        if (desk[j + dx[d]][k + dy[d]] == rel[curr][n]) {
                            nears++;
                        }
                    }
                    if (desk[j + dx[d]][k + dy[d]] == 0) cnt++;
                }
                if ((nears > maxNears) || 
                (nears == maxNears && cnt > max) || 
                ((nears == maxNears && cnt == max && (j < newX || (j == newX && k < newY))))){
                    maxNears = nears;
                    newX = j;
                    newY = k;
                    max = cnt;
                }
            }
        }
        desk[newX][newY] = curr;
        vis[newX][newY] = true;
    }

    int ans = 0;
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                if (i + dx[d] < 0 || i + dx[d] >= n || j + dy[d] < 0 || j + dy[d] >= n) continue;
                for (int n = 0; n < 4; n++) {
                    if (desk[i + dx[d]][j + dy[d]] == rel[desk[i][j]][n]) {
                        cnt++;
                        break;
                    }
                }
            }
            if (cnt == 2) ans += 10;
            else if (cnt == 3) ans += 100;
            else if (cnt == 4) ans += 1000;
            else ans += cnt;
        }
    }
    cout << ans;
}