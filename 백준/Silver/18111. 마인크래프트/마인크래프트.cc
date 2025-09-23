// 1% 틀렸습니다.
//32,000,000,000

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    int n, m;
    long long b;
    cin >> n >> m >> b;
    vector<vector<int>> arr(n, vector<int>(m, 0));
    int high = 0, low = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            arr[i][j] = num;
            high = max(high, num);
            low = min(low, num);
        }
    }
    vector<int> dp(high+1, 0); //높이 인덱스 - 값 : 시간
    long long currB = b;
    for (int i = low; i <= high; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                //인벤토리로 : 2초, 인벤토리에서 1초
                if (arr[j][k] == i) continue;
                if (arr[j][k] > i) {
                    currB += arr[j][k] - i;
                    dp[i] += 2*(arr[j][k] - i);
                } else {
                    currB -= i - arr[j][k];
                    dp[i] += i - arr[j][k];
                }
            }
        }
        if (currB < 0) dp[i] = INT_MAX;
        currB = b;
    }
    int time = dp[low];
    int height = low;
    for (int i = low; i <= high; i++) {
        if (dp[i] <= time) {
            time = dp[i];
            height = i;
        }
    }
    cout << time << " " << height;
}