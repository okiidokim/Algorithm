#include <iostream>
#include <vector>
using namespace std;

int solution(vector<vector<int> > land)
{
    int n = land.size();
    vector<vector<int>> answer(n, vector<int>(4,0));
    for (int i =0; i < 4; i++) answer[0][i] = land[0][i];
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                if (j == k) continue;
                answer[i][j] = max(answer[i][j], answer[i-1][k] + land[i][j]);
            }
        }
    }
    
    int ans = 0;
    for (int i = 0; i < 4; i++) {
        ans = max(ans, answer[n-1][i]);
    }
    return ans;
}