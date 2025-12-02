// 10:40 ~ 12:04 (85분)
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

struct HomeDist {
    int x;
    int y;
    int dist;
};

int n, m, chickCnt;
vector<HomeDist> homes;
vector<pair<int,int>> chickens;
vector<vector<int>> arr(50, vector<int>(50, 0));
int answer;

// 0은 빈 칸, 1은 집, 2는 치킨집
void dfs(int idx) {
    if (chickCnt == m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][j] == 0 || arr[i][j] == 1) continue;
                for (int k = 0; k < homes.size(); k++) {
                    int dist = abs(homes[k].x-i) + abs(homes[k].y-j);
                    homes[k].dist = min(dist, homes[k].dist);
                }
            }
        }
        int sum = 0;
        for (int k = 0; k < homes.size(); k++) {
            sum += homes[k].dist;
            homes[k].dist = INT_MAX;
        }
        answer = min(sum, answer);
        return;
    }

    for (int i = idx; i < chickens.size(); i++) {
        auto [a, b] = chickens[i];
        if (arr[a][b] == 0) continue;
        if (chickCnt < m) continue;;
        arr[a][b] = 0;
        chickCnt--;
        dfs(i+1);
        arr[a][b] = 2;
        chickCnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) homes.push_back({i, j, INT_MAX});
            if (arr[i][j] == 2) {
                chickens.push_back({i, j});
                chickCnt++;
            }
        }
    }

    answer = INT_MAX;
    dfs(0);
    cout << answer;
}