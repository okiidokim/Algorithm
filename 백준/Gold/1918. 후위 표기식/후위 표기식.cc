// 11:26 ~
#include<iostream>
#include<stack>
using namespace std;

int main() {
    string str;
    cin >> str;
    stack<char> s;
    string answer = "";
    for (char c : str) {
        if (c == '(') {
            s.push(c);
            continue;
        }
        if (c == ')') {
            while (s.top() != '(') {
                answer += s.top();
                s.pop();
            }
            s.pop();
            continue;
        }
        if (c <= 'Z' && c >= 'A') {
            answer += c;
            continue;
        }
        if (c == '-' || c == '+') {
            while (!s.empty() && s.top() != '(') {
                answer += s.top();
                s.pop();
            }
            s.push(c);
            continue;
        }
        while(!s.empty() && s.top() != '(' && s.top() != '+' && s.top() != '-') {
            answer += s.top();
            s.pop();
        }
        s.push(c);
    }
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    cout << answer;
}