// 15% 틀렸습니다.

#include<iostream>
using namespace std;

int calNum(string s) {
    int num = 0;
    for (int i = 0; i < s.length(); i++) {
        num += s[i] - '0';
        if (i < s.length() - 1) num *= 10;
    }
    return num;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;

    int answer = 0;

    if (a[0] > '0' && a[0] <= '9') {
        answer = calNum(a) + 3;
    } else if (b[0] > '0' && b[0] <= '9') {
        answer = calNum(b) + 2;
    } else answer = calNum(c) + 1;

    if (answer % 3 == 0 && answer % 5 == 0) cout << "FizzBuzz";
    else if (answer % 3 == 0) cout << "Fizz";
    else if (answer % 5 == 0) cout << "Buzz";
    else cout << answer;
}