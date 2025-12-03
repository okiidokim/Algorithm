// 17:12 ~ 18:18
#include<iostream>
using namespace std;

long long mod = 1000000007;

pair<long long,long long> fib(long long n) {
    if (n == 0) return {0,1};

    auto half = fib(n/2);
    long long fk = half.first;
    long long fk1 = half.second;

    long long two_fk1 = (2 * fk1) % mod;
    long long f2k = (fk * ((two_fk1 - fk + mod) % mod)) % mod;
    long long f2k1 = ((fk * fk) % mod + (fk1 * fk1) % mod) % mod;

    if (n % 2 == 0) {
        return {f2k, f2k1};
    } else {
        return {f2k1, (f2k + f2k1) % mod};
    }
}

int main() {
    long long n;
    cin >> n;
    cout << fib(n).first % mod;
}

//1000000000000000000