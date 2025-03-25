#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int check = 0;
    for (int i = 1; i < n; i++) {
        int sum = i;
        int tmp = i;
        while(tmp > 0) {
            sum += tmp % 10;
            tmp = tmp/10;
        }
        if (n == sum) {
            cout << i;
            check = 1;
            break;
        }
    }
    if (check == 0) cout << 0;
}