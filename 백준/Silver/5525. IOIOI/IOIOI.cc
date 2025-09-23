#include<iostream>
#include<string>
using namespace std;

int main() {
    int n, len;
    string s;
    cin >> n; cin >> len; cin >> s;
    string p = "I";
    for (int i = 0; i < n; i++) p+= "OI";

    int answer = 0;
    for (int i = 0; i < len-p.length()+1; i++) {
        string tmp = s.substr(i, p.length());
        if (tmp == p) answer++;
    }
    cout << answer;
}