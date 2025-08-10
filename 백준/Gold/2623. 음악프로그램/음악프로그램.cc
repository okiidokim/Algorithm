#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> inDegree(n+1, 0);
    vector<vector<int>> vec(n+1);
    for (int i = 0; i < m; i++) {
        int cnt;
        cin >> cnt;
        int arr[cnt];
        for (int j = 0; j < cnt; j++) {
            cin >> arr[j];
        }
        for (int j = 1; j < cnt; j++) {
            vec[arr[j-1]].push_back(arr[j]);
            inDegree[arr[j]]++;
        }
    }
    queue<int> q;
    vector<int> order;
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) q.push(i);
    }
    for (int i = 0; i < n; i++) {
        if (q.empty()) {
            cout << 0 << "\n";
            return 0;
        }

        int curr = q.front(); q.pop();
        order.push_back(curr);
        for (int j = 0; j < vec[curr].size(); j++) {
            int next = vec[curr][j];
            inDegree[next]--;
            if (inDegree[next] == 0) q.push(next);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << order[i] << "\n";
    }
}