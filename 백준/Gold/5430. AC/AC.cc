// 1차 : 16% 틀림

#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--) {
        string cmd;
        cin >> cmd;

        int len;
        cin >> len;
        
        deque<int> dq;
        string s;
        cin >> s;

        int num = 0;
        for (int i = 0; i < s.length(); i++) {
            if (len == 0) break;
            if (s[i] == '[') continue;
            if (s[i] == ']' || s[i] == ',') {
                dq.push_back(num);
                num = 0;
                continue;
            }
            int tmp = s[i] - '0';
            num = num*10 + tmp;                
        }

        int RCnt = 0;
        bool flag = true;
        for (int i = 0; i < cmd.length(); i++) {
            if (cmd[i] == 'R') RCnt++;
            else {
                if (dq.empty()) {
                    cout << "error\n";
                    flag = false;
                    break;
                }
                if (RCnt % 2 == 0) dq.pop_front();
                else dq.pop_back();
            }
        }

        if (!flag) continue;
        if (RCnt %2 == 1) reverse(dq.begin(), dq.end());
        cout << "[";
        if (!dq.empty()) {
            while(dq.size() > 1) {
                cout << dq.front() << ",";
                dq.pop_front();
            }
            cout << dq.front();
        }
        cout << "]\n";
    }
}