// 13:32 ~ 
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int maxNum = 0;

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxNum = max(arr[i], maxNum);
    }

    int m;
    cin >> m;
    int brr[m];
    for (int i = 0; i < m; i++) {
        cin >> brr[i];
        maxNum = max(brr[i], maxNum);
    }

    int aIdx = 0, bIdx = 0;
    vector<int> answer;
    
    while(1) {
        bool found = false;
        for (int i = maxNum; i > 0; i--) {
            int idxFromA = -1;
            for (int j = aIdx; j < n; j++) {
                if (arr[j] == i) {
                    idxFromA = j;
                    break;
                }
            }
            if (idxFromA == -1) continue;

            int idxFromB = -1;
            for (int j = bIdx; j < m; j++) {
                if (brr[j] == i) {
                    idxFromB = j;
                    break;
                }
            }
            if (idxFromB == -1) continue;

            aIdx = idxFromA+1;
            bIdx = idxFromB+1;
            answer.push_back(arr[idxFromA]);
            
            found = true;
            break;
        }
        if (!found) break;
    }

    cout << answer.size() << "\n";
    for (int num : answer) {
        cout << num << " ";
    }
}