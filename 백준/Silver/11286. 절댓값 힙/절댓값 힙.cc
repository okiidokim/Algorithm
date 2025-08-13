#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    priority_queue<int> qminus; //음수
    priority_queue<int, vector<int>, greater<int>> q; //양수
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a == 0) {
            if (qminus.empty() && q.empty()) {
                cout << 0 << "\n";
                continue;
            }
            if (qminus.empty()) {
                cout << q.top() << "\n";
                q.pop();
                continue;
            }
            if (q.empty()) {
                cout << qminus.top() << "\n";
                qminus.pop();
                continue;
            }
            if (abs(qminus.top()) > q.top()) {
                cout << q.top() << "\n";
                q.pop();
            }
            else {
                cout << qminus.top() << "\n";
                qminus.pop();
            }
        }
        else {
            if (a < 0) qminus.push(a);
            else q.push(a);
        }
    }
}