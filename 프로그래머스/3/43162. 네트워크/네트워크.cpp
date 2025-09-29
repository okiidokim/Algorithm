// 19:20 ~ 
#include <string>
#include <vector>

using namespace std;

vector<bool> vis(200, false);

void dfs(int x, int n, vector<vector<int>> computers) {
    for (int i = 0; i < n; i++) {
        if (x == i) continue;
        if (computers[x][i] == 0) continue;
        if (vis[i]) continue;
        vis[i] = true;
        dfs(i, n, computers);
    }    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) continue;
        dfs(i, n, computers);
        answer++;
    }
    return answer;
}