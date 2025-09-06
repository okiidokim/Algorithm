#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first; //오름차순
    else return a.second > b.second; //내림차순
}

int main() {
    int n;
    cin >> n;

    vector<pair<int,int>> work;
    int maxDate = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > maxDate) maxDate = a;
        work.push_back({a, b});
    }

    sort(work.begin(), work.end(), comp);

    vector<int> arr(maxDate, 0);
    for (int i = 0; i < n; i++) {
        auto [day, score] = work[i];
        for (int j = day-1; j >= 0; j--) {
            if (arr[j] == 0) {
                arr[j] += score;
                break;
            }
        }
    }

    int answer = 0;

    for (int i = 0; i < maxDate; i++) {
        answer += arr[i];
    }

    cout << answer;
}