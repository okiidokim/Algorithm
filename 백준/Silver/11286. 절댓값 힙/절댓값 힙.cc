#include<iostream>
#include<queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            if (pq.empty()) {
                cout << 0 <<"\n";
            }
            else {
                cout << pq.top().first * pq.top().second <<"\n";
                pq.pop();
            }
            continue;
        }
        if (num > 0) {
            pq.push({num, 1});
        } else {
            pq.push({abs(num), -1});
        }
    }
}