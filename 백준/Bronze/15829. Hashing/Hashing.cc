#include<iostream>
#include<cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r = 31;
    int m = 1234567891;

    int l;
    string str;
    cin >> l;
    cin >> str;

    long long answer = 0;
    long long currPow = 1;

    for (int i = 0; i < l; i++) {
        int curr = str[i] - 'a' + 1;
        answer = (answer + curr * currPow) % m;
        currPow = (currPow * r) % m;
    }
    cout << answer;
}