// 11:55 ~ 
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

vector<bool> primes(10000000, true);
vector<bool> vis(10000000, false);
vector<bool> used(7, false);
int answer;

void cal() {
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i < 1000; i++) {
        if (!primes[i]) continue;
        for (int j = i+i; j < 10000000; j += i) {
            primes[j] = false;
        }
    }
}

void dfs(string s, int curr, int depth) {
    if (depth > 0) {
        if (!vis[curr] && primes[curr]) {
            ++answer;
        }
        vis[curr] = true;
    }
    for (int i = 0; i < s.length(); i++) {
        if (used[i]) continue;
        used[i] = true;
        dfs(s, curr * 10 + (s[i] - '0'), depth+1);
        used[i] = false;
    }
}


int solution(string numbers) {
    cal();
    
    sort(numbers.begin(), numbers.end());
    dfs(numbers, 0, 0);
    return answer;
}
