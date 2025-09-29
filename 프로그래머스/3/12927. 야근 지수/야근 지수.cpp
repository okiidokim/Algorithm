// 20:05 ~ 20:20
#include <string>
#include <vector>
#include <queue>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> rem;
    for (int w : works) rem.push(w);
    while(!rem.empty() && n > 0) {
        int curr = rem.top(); rem.pop();
        curr--;
        if (curr > 0) rem.push(curr);
        n--;
    }
    if (rem.empty()) return 0;
    while(!rem.empty()) {
        int curr = rem.top(); rem.pop();
        answer += curr * curr;
    }
    return answer;
}