#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        sum += num*num;
    }
    cout << sum%10;
}