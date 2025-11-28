//10:50 ~ 11:14 (25분)
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxNum;

int findTarget(vector<int> arr, int idx) {
    for (int i = idx; i < arr.size(); i++) {
        if (arr[i] == maxNum) {
            idx = i;
            return idx;
        }
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxNum = max(arr[i], maxNum);
    }
    int m;
    cin >> m;
    vector<int> brr(m);
    for (int i = 0; i < m; i++) {
        cin >> brr[i];
        maxNum = max(brr[i], maxNum);
    }

    vector<int> answer;
    int aIdx = 0, bIdx = 0;
    while (1) {
        if (maxNum == 0) break;
        if (aIdx == n || bIdx == m) break;
        int tmpAIdx = findTarget(arr, aIdx);
        int tmpBIdx = findTarget(brr, bIdx);
        if (tmpAIdx == -1 || tmpBIdx == -1) {
            maxNum--;
            continue;
        }
        answer.push_back(maxNum);
        aIdx = tmpAIdx + 1;
        bIdx = tmpBIdx + 1;
    }
    cout << answer.size() << '\n';
    for (int n : answer) cout << n << " ";
}