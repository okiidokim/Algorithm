//10:06 ~ 
#include <string>
#include <vector>
#include<queue>
using namespace std;

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    
    int n = words.size();
    vector<bool> vis(n, false);
    
    queue<string> q;
    q.push(begin);
    
    bool flag = false;
    for (string s : words) {
        if (s == target) {
            flag = true;
            break;
        }
    }
    if (!flag) return 0;
    
    while(!q.empty()) {
        int size = q.size();
        while (size--) {
            string curr = q.front(); q.pop();
            if (curr == target) return answer;
            
            for (int i = 0; i < n; i++) {
                if (vis[i]) continue;
                int count = 0;
                string next = words[i];
                for (int j = 0; j < curr.length(); j++) {
                    if (curr[j] != next[j]) count++;
                }
                if (count != 1) continue;
                vis[i] = true;
                q.push(next);
            }
        }
        answer++;
    }
    return answer;
}