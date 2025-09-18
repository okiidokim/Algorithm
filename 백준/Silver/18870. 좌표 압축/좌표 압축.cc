#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compSecond(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> arr;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back({i, num});
    }
    sort(arr.begin(), arr.end(), compSecond);
    
    int curr = arr[0].second;
    int pressNum = 0;
    for (int i = 0; i < n; i++) {
        auto [index, val] = arr[i];
        if (val == curr) arr[i].second = pressNum;
        else {
            pressNum++;
            arr[i].second = pressNum;
        }
        curr = val;
    }

    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++) {
        cout << arr[i].second << " ";
    }
}