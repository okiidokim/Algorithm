#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, r, c;
    cin >> n >> r >> c;

    int ans = 0;
    int w = 1;
    for (int i = 0; i < n; ++i) {
        int pos = (r % 2) * 2 + (c % 2);
        ans += pos * w;
        r /= 2;
        c /= 2;
        w *= 4;
    }

    cout << ans << '\n';
    return 0;
}