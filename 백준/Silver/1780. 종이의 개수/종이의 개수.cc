#include<iostream>
#include<vector>
using namespace std;

int cnt[3];
const int P3 = 3*3*3*3*3*3*3;
int arr[P3][P3];

bool check(int x, int y, int size) {
    int curr = arr[x][y];
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != curr) return false;
        }
    }
    return true;
}

void solution(int x, int y, int size) {
    if (check(x, y, size)) {
        cnt[arr[x][y] + 1]++;
        return;
    }
    int currSize = size/3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            solution(x + i*currSize, y + j*currSize, currSize);
        }
    }
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    solution(0, 0, n);
    cout << cnt[0] << "\n" << cnt[1] << "\n" << cnt[2];

}