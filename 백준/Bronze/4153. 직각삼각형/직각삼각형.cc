#include<iostream>
using namespace std;

int main() {
    while (1) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) {
            break;
        }
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        if (b > c) {
            int tmp = b;
            b = c;
            c = tmp;
        }
        if (c*c == a*a + b*b) {
            cout << "right" << "\n";
        } else {
            cout << "wrong" << "\n";
        }
    }
}