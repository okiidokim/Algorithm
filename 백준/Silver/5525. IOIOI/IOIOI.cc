#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    string s;
    cin >> N >> M >> s;

    int ans = 0, run = 0;
    for (int i = 0; i + 2 < M; ) {
        if (s[i] == 'I' && s[i+1] == 'O' && s[i+2] == 'I') {
            run++;
            if (run >= N) ans++;
            i += 2;
        } else {
            run = 0;
            i++;
        }
    }
    cout << ans;
}
