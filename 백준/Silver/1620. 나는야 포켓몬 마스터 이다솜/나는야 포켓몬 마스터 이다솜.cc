#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    unordered_map<string, int> pkm;
    unordered_map<int, string> pkmItoS;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        pkm.insert({s, i});
        pkmItoS.insert({i, s});
    }

    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if (s[0] <= '9' && s[0] >= '0') {
            int idx = stoi(s);
            cout << pkmItoS[idx] << "\n";
        } else {
            cout << pkm[s] << "\n";
        }
    }
}