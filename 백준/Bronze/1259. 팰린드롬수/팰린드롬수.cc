#include<iostream>
using namespace std;

int main() {
    while (1) {
        int num;
        cin >> num;
        if (num == 0) return 0;
        string s = to_string(num);
        bool flag = true;
        for (int i = 0; i < s.length()/2; i++) {
            if (s[i] != s[s.length()-i-1]) {
                flag = false;
                break;
            }
        }
        if (flag) cout << "yes\n";
        else cout << "no\n";
    }
}