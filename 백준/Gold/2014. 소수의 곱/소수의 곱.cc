// dfs인가? -> dp인가? 감 안 와서 결국 분류 봄
// 1차 : 32% 틀렸습니다.

#include<iostream>
#include<queue>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int primes[n];
    for (int i = 0; i < n; i++) cin >> primes[i];
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) pq.push(primes[i]);
    for (int i = 1; i < m; i++) {
        long long curr = pq.top(); pq.pop();
        for (int j = 0; j < n; j++) {
            long long next = curr * primes[j];
            pq.push(next);
            if (curr % primes[j] == 0) break; //나눠진다면 이미 한번 pq에 들어왔던 값들이기 때문에 중복으로 들어가는 걸 방지
        }
    }
    cout << pq.top();
}