#include<iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    int home[15][15];

    for (int i = 0; i < 15; i++) {
        home[0][i] = i;
    }
    for (int i = 1; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            int sum = 0;
            for (int k = 0; k <= j; k++) {
                sum += home[i-1][k];
            }
            home[i][j] = sum;
        }
    }

    while(t--) {
        int n, k;
        cin >> n >> k;

        cout << home[n][k] <<"\n";
    }
}