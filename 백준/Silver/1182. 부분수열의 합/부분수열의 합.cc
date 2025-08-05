#include<iostream>
using namespace std;

int n, s;
int num[21];
int cnt, sum;

void dfs(int x) { //백트래킹
    if (x == n) {
        if (sum == s) cnt++;
        return;
    }
    sum += num[x];
    dfs(x+1);
    sum -= num[x];
    dfs(x+1);
}

int main() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) cin >> num[i];
    dfs(0);
    if (s == 0) cnt--; //공집합일 경우 합은 0이므로 한 개 빼줘야 함
    cout << cnt;
}