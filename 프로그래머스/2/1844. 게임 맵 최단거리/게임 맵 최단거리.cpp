#include<vector>
#include<climits>
#include<queue>
#include<vector>
using namespace std;

int solution(vector<vector<int> > maps)
{
    if (maps[0][0] == 0) return -1;
    
    int n = maps.size();
    int m = maps[0].size();
    
    int depth = 1;
    vector<vector<bool>> vis(n, vector<bool>(m, 0));
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    
    queue<pair<int,int>> q;
    q.push({0,0});
    vis[0][0] = true;
    
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            auto [x, y] = q.front(); q.pop();
            if (x == n-1 && y == m-1) return depth;
            
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                
                if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
                if (vis[nx][ny]) continue;
                if (maps[nx][ny] == 0) continue;
        
                vis[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        depth++;
    }
    
    return -1;
}