#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    if (n == k && k == 1) {
        cout << "<1>";
        return 0;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    cout << "<";
    while(q.size() > 1) {
        for (int i = 0; i < k-1; i++) {
            int curr = q.front(); q.pop();
            q.push(curr);
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">";
}