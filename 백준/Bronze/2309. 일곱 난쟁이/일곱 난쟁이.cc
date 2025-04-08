#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n = 9;
    int baby[n];
    for (int i = 0; i < n; i++) {
        cin >> baby[i];
    }
    sort(baby, baby + n);
    int a = 0, b = 1;
    bool doBreak = false;
    
        for (int i = 0; i < n; i++) {
            a = 0;
            for (int j = 0; j < n; j++) {
                int sum = 0;
                for (int i = 0; i < n; i++) {
                    if (i == a || i == b) continue;
                    sum += baby[i];
                }
                if (sum == 100) {
                    doBreak = true;
                    break;
                }
                a++;
            }
            if (doBreak) break;
            b++;
        }
    
    for (int i = 0; i < n; i++) {
        if (i == a || i == b) continue;
        cout << baby[i] << "\n";
    }
}