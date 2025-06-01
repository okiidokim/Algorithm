#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int num[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += num[j];
            if (sum == m) cnt++;
        }
    }
    cout << cnt;
}