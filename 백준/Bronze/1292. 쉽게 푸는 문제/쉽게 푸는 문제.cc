#include<iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    int sum = 0; //구간 합
    int k = 1; //인덱스에 맞는 숫자 조절
    int cnt = 1; //인덱스에 맞는 숫자의 개수
    for (int i = 0; i < b; i++) {
        if (i > a-2 && i < b) {
            sum += k;
        }
        if (cnt == k) {
            k++;
            cnt = 0;
        }
        cnt++;
    }
    cout << sum;
}