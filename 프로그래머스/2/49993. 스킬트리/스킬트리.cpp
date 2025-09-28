#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;

    vector<int> vis(26,0);
    for (int i = 0; i < skill.length(); i++) {
        int index = skill[i] - 'A';
        vis[index] = i+1;
    }
    for (string s : skill_trees) {
        int skillIndex = 0;
        bool flag = true;
        for (char c : s) {
            int idx = c - 'A';
            if (vis[idx] == 0) continue;
            if (skill[skillIndex] == c) {
                skillIndex++;
                continue;
            }
            flag = false;
            break;
        }
        if (flag) answer++;
    }
    
    return answer;
}