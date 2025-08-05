#include<iostream>
using namespace std;

long long a, b, c;
long long cal(long long x) {
    if (x == 0) return 1;
    if (x%2 == 0) return (cal(x/2) * cal(x/2)) % c;
    else return (cal(x/2) * cal(x/2))%c * a%c;
}

int main() {
    cin >> a>> b >> c;
    long long num = cal(b);
    cout << num;
}