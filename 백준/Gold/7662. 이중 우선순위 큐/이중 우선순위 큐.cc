#include<iostream>
#include<set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        multiset<int> ms;
        while (n--) {
            char c;
            int num;
            cin >> c >> num;
            if (c == 'I') {
                ms.insert(num);
            } else {
                if (num == -1) {
                    if (ms.empty()) continue;
                    ms.erase(ms.begin());
                } else {
                    if (ms.empty()) continue;
                    ms.erase(prev(ms.end()));
                }
            }
        }

        if (ms.empty()) cout << "EMPTY\n";
        else cout << *prev(ms.end()) << " " << *ms.begin() << "\n";
    }
}