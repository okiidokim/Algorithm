#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool comp(pair<int, int> a, pair<int,int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first > b.first;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> conf;
    for (int i = 0; i < n; i++) {
        int s, e;
        cin >> s >> e;
        conf.push_back({s, e});
    }

    sort(conf.begin(), conf.end(), comp);

    int answer = 1;
    int currS = conf[0].first;
    int currE = conf[0].second;
    for (int i = 1; i < n; i++) {
        auto [s, e] = conf[i];
        if (currS < e) continue;
        currE = e;
        currS = s;
        answer++;
    }
    cout << answer;
}