// 8/15 (금) 21:05 ~
// 1차 : 89% 틀렸습니다.

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<bool> isPrime(n+1, false);
    int cnt = 0;
    for (int i = 2; i < n+1; i++) {
        if (isPrime[i]) continue;
        isPrime[i] = true;
        cnt++;
        if (cnt == k) {
            cout << i;
            return 0;
        }
        for (int j = i*i; j < n+1; j += i) {
            if (isPrime[j]) continue;
            isPrime[j] = true;
            cnt++;
            if (cnt == k) {
                cout << j;
                return 0;
            }
        }
    }
}