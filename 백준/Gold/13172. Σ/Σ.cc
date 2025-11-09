//17:00 ~ 18:11
#include <iostream>
#include <vector>
#include<numeric>
using namespace std;

// long long gcd(long long a, long long b) {
//     while (b != 0) {
//         long long r = a % b;
//         a = b;
//         b = r;
//     }
//     return a;
// }

int main() {
    long long mod = 1000000007;
    int m;
    cin >> m;

    long long answer = 0;
    for (int i = 0; i < m; i++) {
        long long n, s;
        cin >> n >> s;
        
        long long d = gcd(n, s);
        n = n/d;
        s = s/d;

        long long base = n%mod;
        long long res = 1;
        long long exp = mod-2;
        while (exp > 0) {
            if (exp % 2 == 1) {
                res = base * res;
                res %= mod;
            }
            base = base * base;
            base %= mod;
            exp /= 2;
        }
        n = res;
        
        long long num = (n % mod) * (s % mod);
        answer += num;
        answer %= mod;
    }

    cout << answer;
    return 0;
}
