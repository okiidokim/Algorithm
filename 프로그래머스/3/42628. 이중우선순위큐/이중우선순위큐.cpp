#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    multiset<int> ms;
    for (string s : operations) {
        if (s[0] =='I') {
            int num = stoi(s.substr(2));
            ms.insert(num);
        } else {
            if (ms.size() == 0) continue;
            if (s[2] == '1') {
                ms.erase(prev(ms.end()));
            } else {
                ms.erase(ms.begin());
            }
        }
    }
    
    if (ms.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(*prev(ms.end()));
        answer.push_back(*ms.begin());
    }
    return answer;
}