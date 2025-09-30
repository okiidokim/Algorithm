//11:06 ~ 11:17
#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int Ai = 0, Bi = 0, len = A.size();
    while (Ai < len && Bi < len) {
        if (A[Ai] >= B[Bi]) {
            Bi++;
            continue;
        }
        answer++;
        Ai++;
        Bi++;
    }
    return answer;
}