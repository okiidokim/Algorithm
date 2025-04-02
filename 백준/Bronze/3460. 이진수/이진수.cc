#include<iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int num;
        int loc = 0;
        cin >> num;
        while (num > 0) {
            if (num % 2 == 1) {
                cout << loc << " ";
            }
            loc++;
            num /= 2;
        }
        cout << "\n";
    }
}