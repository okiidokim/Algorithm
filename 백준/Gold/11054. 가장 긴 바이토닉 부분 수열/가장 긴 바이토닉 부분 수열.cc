// 16:37 ~ 16:46 (10분)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> inc(n, 1);
    vector<int> dec(n, 1);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                inc[i] = max(inc[j] + 1, inc[i]);
            }
        }
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= i; j--) {
            if (arr[i] > arr[j]) {
                dec[i] = max(dec[i], dec[j] + 1);
            }
        }
    }

    int answer = 0;
    for (int i = 0; i < n; i++) {
        answer = max(answer, inc[i] + dec[i] - 1);
    }
    cout << answer;
}