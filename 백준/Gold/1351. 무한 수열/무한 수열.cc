// 8/6(수) 13:55 ~ 
// 1중 for문 - tc3에서 시간 초과 (bottom up)
// top down 재귀를 돌아야겠다고 생각함 -> 틀렸습니다
// 다시 bottom up 재귀로 가되 unordered_map으로 -> 메모리 초과
// 다시 재귀 top down 접근 => 대신 p, q 따로 돌지 않고 한 dfs 안에서 돌고 더하게 바꿈 => 71% 시간 초과

#include<iostream>
#include<unordered_map>
using namespace std;

long long p, q;
unordered_map<long long, long long> memo; //얘가 A배열의 역할을 하지만 중복 없어서 탐색 복잡도가 O(1)

long long dfs(long long x) {
    if (x == 0) return 1;
    if (memo.count(x)) return memo[x]; //count 함수 : 해당 키가 존재하면 1, 없으면 0
    return memo[x] = dfs(x/p) + dfs(x/q);
}

int main() {
    long long n;
    cin >> n >> p >> q;
    cout << dfs(n);
}