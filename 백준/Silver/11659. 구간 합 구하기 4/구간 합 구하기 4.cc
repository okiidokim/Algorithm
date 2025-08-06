#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    int arr[n+1];
    int sum[n+1];
    sum[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a-1] << "\n";
    }
}