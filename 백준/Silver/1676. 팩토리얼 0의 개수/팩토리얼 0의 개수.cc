#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int answer = 0;
    for (int i = 5; i <= n; i *= 5) {
        answer += n/i;
    }
    cout << answer;
}