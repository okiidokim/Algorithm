//22:57 ~ 
#include <string>
#include <vector>
#include<iostream>
using namespace std;

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    int n = 0;
    for (int i = 0; i < edges.size(); i++) {
        int tmp = max(edges[i][0], edges[i][1]);
        n = max(tmp, n);
    }
    
    vector<int> out(n+1, 0);
    vector<int> in(n+1, 0);
    for (int i = 0; i < edges.size(); i++) {
        int s = edges[i][0];
        int e = edges[i][1];
        out[s]++;
        in[e]++;
    }
    
    int last = 0;
    for (int i = 1; i <= n; i++) {
        if (out[i] > 1 && in[i] == 0) {
            last = i;
            break;
        }
    }
    
    int stick = 0, eight = 0; 
    for (int i = 1; i <= n; i++) {
        if (i == last) continue;
        if (out[i] >= 2 && in[i] >= 2) eight++;
        if (in[i] >= 1 && out[i] == 0) stick++;
    }
    int donut = out[last] - eight - stick;
    answer.push_back(last);
    answer.push_back(donut);
    answer.push_back(stick);
    answer.push_back(eight);
    return answer;
}