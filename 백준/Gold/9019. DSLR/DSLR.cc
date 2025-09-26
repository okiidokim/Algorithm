//17% 틀렸습니다.

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        vector<string> ans(10001, "");
        queue<int> q;
        q.push(a);
        while(!q.empty()) {
            int curr = q.front(); q.pop();
            if (curr == b) break;

            int d = curr * 2; d = d % 10000;
            if (d != a && ans[d] == "") {
                ans[d] = ans[curr] + "D";
                q.push(d);
            }

            int s = curr-1;
            if (s == -1) s = 9999;
            if (s != a && ans[s] == "") {
                ans[s] = ans[curr] + "S";
                q.push(s);
            }

            int rem = curr % 1000;
            int d1 = curr / 1000;
            int l = rem * 10 + d1;
            if (l != a && ans[l] == "") {
                ans[l] = ans[curr] + "L";
                q.push(l);
            }

            rem = curr % 10; //d4
            d1 = curr / 10; //d1 d2 d3
            int r = rem * 1000 + d1;
            if (r != a && ans[r] == "") {
                ans[r] = ans[curr] + "R";
                q.push(r);
            }
        }
        cout << ans[b] << "\n";
    }
}