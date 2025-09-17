#include <string>
#include <vector>
using namespace std;

vector<bool> arr(1000001, true);
void erase() {
    for (int i = 2; i < 1001; i++) {
        for (int j = i*2; j < arr.size(); j += i) {
            arr[j] = false;
        }
    }
}

int solution(int n) {
    int answer = 0;
    erase();
    for (int i = 2; i <= n; i++) {
        if (arr[i]) answer++;
    }
    return answer;
}