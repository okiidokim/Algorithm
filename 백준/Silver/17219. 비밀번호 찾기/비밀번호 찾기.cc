#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, q;
    cin >> n >> q;
    unordered_map<string, string> site;
    for (int i = 0; i < n; i++) {
        string s, pw;
        cin >> s >> pw;
        site.insert({s, pw});
    }
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        cout << site[s] << "\n";
    }
}