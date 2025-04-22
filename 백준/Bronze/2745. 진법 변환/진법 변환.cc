#include<iostream>
#include<cmath>
using namespace std;

int main() {
    string num;
    int b;
    cin >> num >> b;
    int res = 0;
    for (int i = 0; i < num.length(); i++) {
        int changed = 0;
        if (num[num.length() - i - 1] >= 'A' && num[num.length() - i - 1] <= 'Z') {
            changed = num[num.length() - i - 1] - 'A' + 10;
        } else {
            changed = num[num.length() - i - 1] - '0';
        }
        changed = changed * pow(b, i);
        res += changed;
    }
    cout << res;
}