#include<iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int num[n];
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    int max = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int sum = num[i] + num [j] + num[k];
                if (sum <= m && max < sum) {
                    max = sum;
                }
            }
        }
    }
    cout << max;
}