#include<iostream>
using namespace std;

int main() {
    int ppl;
    cin >> ppl;
    int cnt[6];
    for (int i = 0; i < 6; i++) {
        cin >> cnt[i];
    }
    int t,pen;
    cin >> t >> pen;
    int tSum = 0;
    for (int i = 0; i < 6; i++) {
        if (cnt[i] % t == 0) {
            tSum += cnt[i]/t;
        } else {
            tSum += cnt[i]/t + 1;
        }
    }
    cout << tSum << "\n";
    cout << ppl/pen << " " << ppl%pen;
}