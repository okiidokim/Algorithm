#include<iostream>
#include<unordered_set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    unordered_set<int> s;
    while (n--) {
        string str;
        cin >> str;
        if (str == "all") {
            for (int i = 1; i <= 20; i++) {
                s.insert(i);
            }
            continue;
        } 
        if (str == "empty") {
            s.clear();
            continue;
        }
        int num;
        cin >> num;
        if (str == "add") {
            s.insert(num);
        } else if (str == "remove") {
            s.erase(num);
        } else if (str == "check") {
            if (s.find(num) != s.end())  cout << "1\n";
            else cout << "0\n";
        } else if (str == "toggle") {
            if (s.find(num) != s.end())  s.erase(num);
            else s.insert(num);
        }
    }
}