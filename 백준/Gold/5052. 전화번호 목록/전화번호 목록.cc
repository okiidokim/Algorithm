#include<iostream>
#include<algorithm>
using namespace std;

// 8/7(목) 13:00 ~ 
// 1차 : 10% 시간 초과

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;
        string s[n];
        for (int j = 0; j < n; j++) cin >> s[j];
        sort(s, s+n);
        bool flag = true;
        for (int j = 1; j < n; j++) {
            if (s[j].rfind(s[j-1],0) == 0) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}