#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, h;
    cin >> n >> h;

    vector<int> suk(h + 2, 0);
    vector<int> jong(h + 2, 0);

    for (int i = 0; i < n; i++) {
        int len;
        cin >> len;
        if (i % 2 == 0) suk[len]++;
        else jong[len]++;
    }

    for (int i = h - 1; i >= 1; --i) {
        suk[i]  += suk[i + 1];
        jong[i] += jong[i + 1];
    }

    int best = INT_MAX;
    int ways = 0;

    for (int i = 1; i <= h; ++i) {
        int cnt = suk[i] + jong[h - i + 1];

        if (cnt < best) {
            best = cnt;
            ways = 1;
        } else if (cnt == best) {
            ways++;
        }
    }

    cout << best << ' ' << ways;
    return 0;
}
