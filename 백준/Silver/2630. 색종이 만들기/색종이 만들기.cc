#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    int paper[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> paper[i][j];
    }

    vector<vector<bool>> vis(n, vector<bool>(n, false));
    int blues = 0, whites = 0;
    int size = n;
    while (size > 0) {
        bool flag = true;
        for (int a = 0; a < n; a += size) {
            for (int b = 0; b < n; b += size) {
                if (vis[a][b]) continue;
                int curr = paper[a][b];
                for (int i = a; i< a+size; i++) {
                    for (int j = b; j < b+size; j++) {
                        if (paper[i][j] != curr) {
                            flag = false;
                            break;
                        }
                    }
                    if (!flag) break;
                }
                if (flag) {
                    if (curr == 0) whites++;
                    else blues++;
                    for (int i = a; i<a+size; i++) {
                        for (int j = b; j < b+size; j++) {
                            vis[i][j] = true;
                        }
                    }
                }
                flag = true;
            }
        }
        size /= 2;
    }
    cout << whites << "\n" << blues;
}