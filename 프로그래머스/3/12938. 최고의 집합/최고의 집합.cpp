#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    while (n > 1) {
        answer.push_back(s/n);
        s -= s/n;
        if (s/n == 0) return {-1};
        if (n == 2) answer.push_back(s);
        n--;
    }
    //3, 10
    //3 3 4 = 36
    return answer;
}