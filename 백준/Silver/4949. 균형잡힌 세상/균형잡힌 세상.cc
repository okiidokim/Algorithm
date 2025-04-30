#include<iostream>
#include<stack>
using namespace std;

int main() {
    string str = "";
    while (1) {
        getline(cin, str);
		if (str.length() == 1 && str[0] == '.') break;
        bool isBalanced = true;
        stack<char> s;
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(' || str[i] == '[') {
                s.push(str[i]);
            } else if (str[i] == ')') {
                if (s.empty()) {
                    isBalanced = false;
                    break;
                } else if (s.top() == '(') {
                    s.pop();
                } else {
                    isBalanced = false;
                    break;
                }
            } else if (str[i] == ']') {
                if (s.empty()) {
                    isBalanced = false;
                    break;
                } else if (s.top() == '[') {
                    s.pop();
                } else {
                    isBalanced = false;
                    break;
                }
            }
        }
        if (!s.empty()) {
            isBalanced = false;
        }
        if (isBalanced) {
            cout << "yes\n";
        } else {
            cout << "no\n";
        }
    }
}