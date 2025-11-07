// 13:35 ~ 13:47
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int n;
    long long b;
    cin >> n >> b;
    int mod = 1000;
    vector<vector<int>> arr(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            arr[i][j] %= mod;
        }
    }
    
    vector<vector<int>> answer(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) answer[i][i] = 1;

    vector<vector<int>> update = arr;
    while (b > 0) {
        if (b % 2 == 1) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    int next = 0;
                    for (int k = 0; k < n; k++) {
                        next += answer[i][k] * arr[k][j];
                        next %= mod;
                    }
                    update[i][j] = next;
                }
            }
            answer = update;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int next = 0;
                for (int k = 0; k < n; k++) {
                    next += arr[i][k] * arr[k][j];
                    next %= mod;
                }
                update[i][j] = next;
            }
        }
        arr = update;
        b /= 2;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << answer[i][j] <<" ";
        }
        cout << "\n";
    }
}