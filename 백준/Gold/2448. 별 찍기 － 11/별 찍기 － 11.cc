// 14:20 ~ 15:40 (1시간 20분)
#include<iostream>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;

int n;

void dfs(int x, int y, int h, vector<vector<char>>& stars) {
    if (h == 3) {
        stars[x][y] = '*';
        stars[x+1][y-1] = '*';
        stars[x+1][y+1] = '*';
        for (int i = y-2; i <= y+2; i++) stars[x+2][i]= '*';
        return;
    }
    int height = h/2;
    dfs(x, y, height, stars);
    dfs(x+height, y-height, height, stars);
    dfs(x+height, y+height, height, stars);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    vector<vector<char>> stars(n, vector<char>(2*n-1, ' '));
    dfs(0, n-1, n, stars);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < stars[i].size(); j++) {
            cout << stars[i][j];
        }
        cout << "\n";
    }
}