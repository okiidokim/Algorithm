//11:20 ~ 11:40

#include <string>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int>> arr) {
    vector<int> crashed;
    int n = arr.size();
    int size = n;
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    while (n > 0) {
        for (int i = 0; i < size; i += n) {
            for (int j = 0; j < size; j += n) {
                if (vis[i][j]) continue;
                int curr = arr[i][j];
                bool flag = true;
                for (int x = i; x < i+n; x++) {
                    for (int y = j; y < j + n; y++) {
                        if (vis[x][y]) continue;
                        if (curr == arr[x][y]) continue;
                        flag = false;
                        break;
                    }
                    if (!flag) break;
                }
                if (flag) {
                    crashed.push_back(curr);
                    for (int x = i; x < i+n; x++) {
                        for (int y = j; y < j + n; y++) {
                            vis[x][y] = true;
                        }
                    }
                }
            }
        }
        n /= 2;
    }
    
    int ones = 0;
    int zeros = 0;
    for (int i = 0; i < crashed.size(); i++) {
        if (crashed[i] == 0) zeros++;
        else ones++;
    }
    return {zeros, ones};
}

