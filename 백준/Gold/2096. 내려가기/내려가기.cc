// 20:12 ~ 20:46 (34분)
// 1차, 2차 : 메모리 초과

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    
    vector<int> min_dp(3, 0);
    vector<int> max_dp(3, 0);
    for (int i = 0; i < 3; i++) {
        min_dp[i] = arr[i];
        max_dp[i] = arr[i];
    }

    for (int i = 1; i < n; i++) {
        cin >> arr[0] >> arr[1] >> arr[2];

        int tmp[3];

        tmp[0] = min(min_dp[0], min_dp[1]) + arr[0];
        tmp[1] = min({min_dp[0], min_dp[1], min_dp[2]}) + arr[1];
        tmp[2] = min(min_dp[1], min_dp[2]) + arr[2];
        min_dp[0] = tmp[0]; min_dp[1] = tmp[1]; min_dp[2] = tmp[2]; 

        tmp[0] = max(max_dp[0], max_dp[1]) + arr[0];
        tmp[1] = max({max_dp[0], max_dp[1], max_dp[2]}) + arr[1];
        tmp[2] = max(max_dp[1], max_dp[2]) + arr[2];
        max_dp[0] = tmp[0]; max_dp[1] = tmp[1]; max_dp[2] = tmp[2]; 
    }

    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << " " << min({min_dp[0], min_dp[1], min_dp[2]});
}