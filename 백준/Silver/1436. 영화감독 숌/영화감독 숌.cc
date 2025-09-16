#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int curr = 666;
    int index = 0;
    while (1) {
        if (to_string(curr).find("666") != string::npos) {
            index++;
            if (index == n) break;
        }
        curr++;
    }
    cout << curr;
}