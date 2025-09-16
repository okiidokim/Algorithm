#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int main() {
    stack<int> s;
    int n;
    cin >> n;
    int size = n;

    int fN = 0;
    vector<char> answer;

    while (n--) {
        int num;
        cin >> num;
        if (fN < num) {
            for (int i = fN + 1; i <= num; i++) {
                s.push(i);
                answer.push_back('+');
            }
            fN = num;
        }
        if (num < s.top()) break;
        if (s.top() == num) {
            s.pop();
            answer.push_back('-');
        }
    }
    if (!s.empty()) {
        cout << "NO";
        return 0;
    }
    for (int i = 0; i < answer.size(); i++) cout << answer[i] << "\n";
}