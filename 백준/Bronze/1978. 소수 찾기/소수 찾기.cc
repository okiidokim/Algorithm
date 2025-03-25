#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        int isPrime = true;
        if (a == 1) continue;
        for (int j = 2; j < 30; j++) {
            if (a!=j  && a % j == 0) {
                isPrime = false;
                break;
            }
        }
        isPrime ? cnt++ : cnt;
    }
    cout << cnt;
}