#include<iostream>
#include<deque>
using namespace std;

int main() {
    int n, pick;
    cin >> n >> pick;
    
    deque<int> dq;
    for (int i = 0; i < n; i++) {
        dq.push_back(i+1);
    }
    int cnt = 0;
    for (int i = 0; i < pick; i++){
        int pickNum;
        cin >> pickNum;
        
        deque<int> dqB = dq;
        int tmpCnt1 = 0, tmpCnt2 = 0;
        
        while (dq.front() != pickNum) {
            int tmp = dq.front();
            dq.pop_front();
            dq.push_back(tmp);
            tmpCnt1++;
        }
        
        while (dqB.front() != pickNum) {
            int tmp = dqB.back();
            dqB.pop_back();
            dqB.push_front(tmp);
            tmpCnt2++;
        }
        
        if (tmpCnt1 < tmpCnt2) {
            dq.pop_front();
            cnt += tmpCnt1;
        } else {
            dqB.pop_front();
            cnt += tmpCnt2;
            dq = dqB;
        }
    }
    cout << cnt;
}