// 1: 시간초과
// 2: 6% 틀렸습니다.

#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> ones(41, 0);
    vector<int> zeros(41, 0);
    ones[0] = 0; zeros[0] = 1;
    ones[1] = 1; zeros[1] = 0;

    for (int i = 2; i <= 40; i++) {
        zeros[i] = zeros[i-1] + zeros[i-2];
        ones[i] = ones[i-1] + ones[i-2];
    }

    while(n--) {
        int num;
        cin >> num;
        cout << zeros[num] << " " << ones[num] << "\n";
    }
}