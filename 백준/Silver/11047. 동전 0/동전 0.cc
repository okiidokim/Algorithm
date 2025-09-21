#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    int coins[n];
    for (int i = 0; i < n; i++) cin >> coins[i];

    int answer = 0;
    for (int i = n-1; i >= 0; i--) {
        int mok = m / coins[i];
        int nam = m % coins[i];
        answer += mok;
        m = nam;
    }
    cout << answer;
}