#include<iostream>
#include<stack>
using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        stack<char> s;
        bool flag = true;
        for (int j = 0; j < str.length(); j++) {
            if (str[j] == '(') {
                s.push('(');
                continue;
            }
            if (s.empty()) {
                flag = false;
                break;
            }
            s.pop();
        }
        if (s.empty() && flag) cout << "YES\n";
        else cout << "NO\n";
    }
}