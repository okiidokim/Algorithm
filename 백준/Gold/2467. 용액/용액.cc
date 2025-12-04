//18:00 ~ 18:23
#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> liq;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        liq.push_back(val);
    }
    int left = 0, right = n-1;
    if (liq[right] <= 0) {
        cout << liq[right-1] << " " << liq[right];
        return 0;
    }
    if (liq[left] >= 0) {
        cout << liq[left] << " " << liq[left + 1];
        return 0;
    }

    int sum = INT_MAX;
    int resL = left, resR = right;
    while (left < right) {
        if (abs(liq[left] + liq[right]) < sum) {
            resL = left;
            resR = right;
            sum = abs(liq[left] + liq[right]);
        }

        int a = abs(liq[left]);
        int b = abs(liq[right]);
        if (a < b) right--;
        else left++;
    }
    cout << liq[resL] << " " << liq[resR];
}