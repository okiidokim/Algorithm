#include<iostream>
#include<queue>
using namespace std;

int main() {
    int t;
    cin >> t;
    int n = 10;
    int rank = 3;
    for (int i = 0; i < t; i++) {
        priority_queue<int> pq;
        for (int i = 0; i<n; i++) {
            int num;
            cin >> num;
            pq.push(num);
        }
        pq.pop(); pq.pop();
        cout << pq.top() << "\n";
    }
}