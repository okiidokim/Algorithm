// 1% 틀렸습니다.

#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    
    int except = floor((double)n * 0.15 + 0.5);

    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    int sum = 0;
    for (int i = except; i < n-except; i++) sum += arr[i];
    double answer = (double)sum / (n - except*2);
    cout << floor(answer + 0.5);
}