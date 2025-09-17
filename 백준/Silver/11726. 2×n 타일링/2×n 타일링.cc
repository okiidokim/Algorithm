#include<iostream>
using namespace std;

int main() {
    int f[1000];
    f[1] = 1;
    f[2] = 2;
    int mod = 10007;
    
    int n;
    cin >> n;
    for (int i = 3; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
        f[i] %= mod;
    }
    cout << f[n];
}