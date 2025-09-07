// 1차 : 1% 틀렸습니다.

#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;

bool comp(tuple<int,int,int> t1, tuple<int,int,int> t2) {
    return get<1>(t1) < get<1>(t2);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n>> m;
    vector<tuple<int,int,int>> ppl;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ppl.push_back({a, i, 0}); //상사, 나, 점수
    }

    for (int i = 0; i <m; i++) {
        int a, b;
        cin >> a >> b;
        get<2>(ppl[a-1]) += b;
    }

    sort(ppl.begin(), ppl.end());

    for (int i = 1; i < n; i++) {
        int curr = i;
        int bef = i-1;
        while (get<0>(ppl[curr]) == get<0>(ppl[bef]) || get<1>(ppl[bef]) != get<0>(ppl[curr])-1) {
            bef--;
        }
        get<2>(ppl[curr]) += get<2>(ppl[bef]);
    }

    sort(ppl.begin(), ppl.end(), comp);

    for (int i = 0; i < n; i++) cout << get<2>(ppl[i]) << " ";
}