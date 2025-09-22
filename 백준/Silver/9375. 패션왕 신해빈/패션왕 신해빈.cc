//1챠 : 25% 틀렸습니다.

#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n; //옷 가지수
        cin >> n;
        unordered_map<string, int> clothes;
        while(n--) {
            string cl, tp;
            cin >> cl >> tp;
            if (clothes.find(tp) != clothes.end()) clothes[tp]++;
            else clothes.insert({tp, 1});
        }
        int answer = 1;
        for (auto it = clothes.begin(); it != clothes.end(); it++) {
            answer *= it->second+1;
        }
        cout << answer-1 << "\n";
    }
}