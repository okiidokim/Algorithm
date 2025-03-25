#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 1;
    int now = 1;
    while (n > now) {
        now += cnt*6;
        cnt++;
    }
     cout << cnt;
}