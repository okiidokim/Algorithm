#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int a, b;
    cin >> a >> b;
    queue<pair<long long,int>> q;
    q.push({a, 1});
    bool flag = false;
    while (!q.empty()) {
        auto [curr, cnt] = q.front(); q.pop();
        if (curr == b) {
            cout << cnt;
            return 0;
        }

        long long next1 = curr * 2;
        long long next2 = curr * 10 + 1;
        if (next1 <= b) q.push({next1, cnt+1});
        if (next2 <= b) q.push({next2, cnt+1});
    }
    
    cout << -1;
}