#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n % 2 == 0 || m % 2 == 0) {
        cout << "A";
    } else cout << "B";
}