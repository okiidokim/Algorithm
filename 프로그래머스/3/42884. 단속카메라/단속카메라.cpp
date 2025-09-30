//11:40 ~ 
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

bool comp(vector<int> a, vector<int> b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end(), comp);
    int curr = routes[0][1];
    for (int i = 0; i < routes.size(); i++) {
        if (curr < routes[i][0]) {
            answer++;
            curr = routes[i][1];
        } else {
            curr = min(routes[i][1], curr);
        }
    }
    return answer;
}