#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    const int len = 2*w + 1;

    int curr = 1;
    for (int s : stations) {
        int left  = max(1, s - w);
        int right = min(n, s + w);

        if (curr < left) {
            int gap = left - curr;
            answer += (gap + len - 1) / len;
        }
        curr = right + 1;
    }
    if (curr <= n) {
        int gap = n - curr + 1;
        answer += (gap + len - 1) / len;
    }
    return answer;
}
