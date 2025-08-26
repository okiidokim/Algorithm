// 8/26 (화) 12:30 ~ 13:00

#include<iostream>
#include<vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n;
    cin >> n;

    int arr[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    vector<bool> pick(n, false);
    fill(pick.begin(), pick.begin() + n/2, true);
    int gap = INT_MAX;
    do {
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (pick[i] && pick[j]) a += arr[i][j] + arr[j][i];
                else if (!pick[i] && !pick[j]) b += arr[i][j] + arr[j][i];
            }
        }
        gap = min(gap, abs(a - b));
    } while (prev_permutation(pick.begin(), pick.end()));
    
    cout << gap;
}