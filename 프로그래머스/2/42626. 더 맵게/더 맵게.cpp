#include <string>
#include <queue>
#include <vector>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int sc : scoville) pq.push(sc);
        
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        if (a >= K) break;
        int b = pq.top(); pq.pop();
        int next = a + b*2;
        
        pq.push(next);
        answer++;
    }
    
    if (pq.size() > 0 && pq.top() < K) return -1;
    return answer;
}