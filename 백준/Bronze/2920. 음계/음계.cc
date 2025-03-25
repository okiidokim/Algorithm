#include<iostream>
using namespace std;

int main() {
    int music[8];
    int now = 0;
    string result = "ascending";
    for (int i = 0; i < 8; i++) {
        cin >> music[i];
        if (music[i] - i == 1 && result != "descending") {
            result = "ascending";
        } else if (music[i] + i == 8) {
            result = "descending";
        } else {
            result = "mixed";
            break;
        }
    }
    cout << result;
}