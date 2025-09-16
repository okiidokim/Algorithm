// 2% 틀렸습니다.

#include<iostream>
#include<cmath>
#include<climits>
#include<map>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    int sum = 0;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
        if (m.find(arr[i]) != m.end()) m[arr[i]]++;
        else m.insert({arr[i], 1});
    }

    int avg = floor((double)sum / n + 0.5);

    sort(arr, arr+n);
    int mid = arr[n/2];
    int range = arr[n-1] - arr[0];

    int most = m.begin()->first;
    int cnt = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (cnt < iter->second) {
            most = iter->first;
            cnt = iter->second;
        }
    }

    int check = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        if (cnt == iter->second) check++;
        if (check == 2) {
            most = iter->first;
            break;
        }
    }

    cout << avg << "\n" << mid << "\n" << most << "\n" << range;
    //평균 - 반올림
    //중앙값
    //최빈값
    //범위 min, max
}