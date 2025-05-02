#include<iostream>
#include<deque>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
    cin >> n;
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        int cmd;
        cin >> cmd;
        if (cmd == 1) {
            int num;
            cin >> num;
            dq.push_front(num);
            continue;
        } else if (cmd == 2) {
            int num;
            cin >> num;
            dq.push_back(num);
            continue;
        } else if (cmd == 3) {
            if (!dq.empty()) {
                cout << dq.front();
                dq.pop_front();
            } else {
                cout << -1;
            }
            cout << "\n";
            continue;
        } else if (cmd == 4) {
            if (!dq.empty()) {
                cout << dq.back();
                dq.pop_back();
            } else {
                cout << -1;
            }
            cout << "\n";
            continue;
        } else if (cmd == 5) {
            cout << dq.size() << "\n";
            continue;
        } else if (cmd == 6) {
            if (dq.empty()) cout << 1;
            else cout << 0;
            cout << "\n";
            continue;
        } else if (cmd == 7) {
            if (!dq.empty()) {
                cout << dq.front();
            } else {
                cout << -1;
            }
            cout << "\n";
            continue;
        } else if (cmd == 8) {
            if (!dq.empty()) {
                cout << dq.back();
            } else {
                cout << -1;
            }
            cout << "\n";
            continue;
        }
    }
}