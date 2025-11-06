// 14:30 ~ 15:15
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> v;
int idx;

void postOrder(int s, int e) {
    if (idx >= v.size()) return;
    int curr = v[idx];
    if (curr <= s || curr >= e) return;
    
    idx++;

    postOrder(s, curr);
    postOrder(curr, e);
    cout << curr << "\n";
}


int main() {
    int number;
    while (cin >> number) {
        v.push_back(number);
    }
    postOrder(INT_MIN, INT_MAX);
}
