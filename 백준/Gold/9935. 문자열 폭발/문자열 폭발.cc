// 15:54 ~ 17:42 (중간에 잠...;; / 대략 1시간)
#include<iostream>
#include<string>
#include<stack>
#include<algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    string str, xpl;
    cin >> str;
    cin >> xpl;

    stack<char> s;
    int ps = xpl.size();

    for (char c : str) {
        s.push(c);
        if (s.size() >= ps && s.top() == xpl[ps-1]) {
            string tmp = "";
            bool isSame = true;
            for (int i = ps-1; i >= 0; i--) {
                if (xpl[i] != s.top()) {
                    isSame = false;
                    break;
                }
                tmp += s.top();
                s.pop();
            }
            reverse(tmp.begin(), tmp.end());
            if (!isSame) {
                for (int i = 0; i < tmp.size(); i++) {
                    s.push(tmp[i]);
                }
            }
        }
    }

    if (s.empty()) {
        cout << "FRULA";
        return 0;
    }

    string answer = "";
    while (!s.empty()) {
        answer += s.top();
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    cout << answer;
}