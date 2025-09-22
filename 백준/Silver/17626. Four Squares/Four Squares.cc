#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> answer(n+1, INT_MAX); answer[0] = 0;
    vector<int> arr;
    for (int i = 1; i*i <= n; i++) arr.push_back(i*i);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < arr.size(); j++) {
            if (arr[j] > i) break;
            answer[i] = min(answer[i], answer[i-arr[j]] + 1);
        }
    }
    cout << answer[n];
}
