#include<iostream>
using namespace std;

int main() {
    int ppl = 0;
    int maxPpl = 0;
    int stationCnt = 10;
    for (int i = 0; i < stationCnt; i++) {
        int a, b;
        cin >> a >> b;
        ppl = ppl - a + b;
        if (ppl > maxPpl) {
            maxPpl = ppl;
        }
    }
    cout << maxPpl;
}