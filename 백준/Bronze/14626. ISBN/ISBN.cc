//23% 틀렸습니다.

#include<iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    for (int i = 0; i < 10; i++) {
        int sum = 0;
        for (int j = 0; j < s.length(); j++) {
            if (s[j] == '*') {
                if (j % 2 == 0) sum += i;
                else sum += 3*i;
                continue;
            }
            if (j%2 == 0) sum += s[j]-'0';
            else sum += 3*(s[j]-'0');
        }
        if (sum%10 == 0) {
            cout << i;
            return 0;
        }
    }
}