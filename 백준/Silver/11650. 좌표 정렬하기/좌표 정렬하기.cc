#include<iostream>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}


int main() {
    int n;
    cin >> n;
    pair<int, int> point[n];
    for (int i = 0; i < n; i++) {
        cin >> point[i].first >> point[i].second;
    }
    sort(point, point + n, comp);
    for (int i = 0; i < n; i++) {
        cout << point[i].first << " " << point[i].second << "\n";
    }
}