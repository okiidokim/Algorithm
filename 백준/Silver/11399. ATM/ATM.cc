#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);

    for (int i =1; i < n; i++) {
        arr[i] += arr[i-1];
    }
    int answer = 0;
    for (int i = 0; i < n; i++) answer += arr[i];
    cout << answer;
}