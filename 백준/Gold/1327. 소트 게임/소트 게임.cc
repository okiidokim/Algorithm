#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

int n, k;
string str = "";

bool check() {
    for (int i = 0; i < n; i++) {
        if (str[i] != i+'1') return false;
    }
    return true;
}

void reverse(int start) {
    for (int i = 0; i < k/2; i++) {
        int tmp = str[i + start];
        str[i + start] = str[start + k-i-1];
        str[start + k-i-1] = tmp;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        str += '0' + num;
    }

    if (check()) {
        cout << 0;
        return 0;
    }

    queue<string> q;
    q.push(str);
    unordered_map<string, int> um;
    um[str] = 0;
    
    while(!q.empty()) {
        string curr = q.front(); q.pop();
        int cnt = um[curr];
        for (int i = 0; i <= n-k; i++) {
            str = curr;
            reverse(i);
            if (!um[str]) {
                if (check()) {
                    cout << cnt+1;
                    return 0;
                }
                um[str] = cnt+1;
                q.push(str);
            }
        }
    }
    cout << -1;
}