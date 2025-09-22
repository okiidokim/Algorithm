#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long ans[101];
    ans[1] = 1; ans[2] = 1; ans[3] = 1;
    ans[4] = 2; ans[5] = 2;
    for (int i = 6; i < 101; i++) {
        ans[i] = ans[i-1] + ans[i-5];
    }
        
    int t;
    cin >> t;
    while(t--) {
        int num;
        cin >> num;
        cout << ans[num] << "\n";
    }
}