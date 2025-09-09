#include<iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int top = 1;
    int bottom = 1;
    for (int i = n; i > n-k; i--) {
        top *= i;
    }
    for (int i = 2; i <= k; i++) {
        bottom *= i;
    }
    cout << top/bottom;
}