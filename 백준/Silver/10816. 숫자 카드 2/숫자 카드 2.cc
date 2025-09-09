#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    unordered_map<int, int> cards;
    for (int i =0; i < n; i++) {
        int num;
        cin >> num;
        if (!cards[num]) cards[num] = 1;
        else cards[num]++;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        if (cards[num]) cout << cards[num] << " ";
        else cout << 0 << " ";
    }
}