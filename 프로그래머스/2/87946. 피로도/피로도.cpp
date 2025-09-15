#include <string>
#include <vector>

using namespace std;

int vis[10];
int answer;

void dfs(int k, int cleared, vector<vector<int>> dungeons) {
    if (cleared > answer) answer = cleared;
    for (int i = 0; i < dungeons.size(); i++) {
        if (vis[i]) continue;
        int currK = dungeons[i][0];
        int currE = dungeons[i][1];
        if (k >= currK) {
            vis[i] = true;
            dfs(k-currE, cleared+1, dungeons);
            vis[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, 0, dungeons);
    return answer;
}