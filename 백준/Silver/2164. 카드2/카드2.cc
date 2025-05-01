#include<iostream>
#include<deque>
using namespace std;

int main() {
    int num;
    cin >> num;
    deque<int> dq;
    for (int i = 0; i < num; i++) {
        dq.push_back(i+1);
    }
    while (dq.size() > 1) {
        dq.pop_front();
        int tmp = dq.front();
        dq.pop_front();
        dq.push_back(tmp);
    }
    cout << dq.front();
}