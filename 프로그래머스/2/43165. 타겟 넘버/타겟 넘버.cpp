#include<iostream>
#include <string>
#include <vector>
using namespace std;

int answer;
bool vis[20];

void dfs(int x, int sum, int sign, vector<int> numbers, int target) {
    if (x == numbers.size()) {
        if (sum == target) answer++;
        return;
    }
    if (vis[x]) return;
    vis[x] = true;
    sum += sign*numbers[x];
    dfs(x+1, sum, 1, numbers, target);
    dfs(x+1, sum, -1, numbers, target);
    vis[x] = false;
}

int solution(vector<int> numbers, int target) {   
    dfs(0, 0, 1, numbers, target);
    for (int i = 0; i < 20; i++) vis[i] = false;
    dfs(0, 0, -1, numbers, target);
    return answer/2;
}