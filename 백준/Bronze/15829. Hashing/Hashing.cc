#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int n;
    string str;
    cin >> n;
    cin >> str;
    int hashResult = 0;
    for (int i  = 0;i < str.length(); i++) {
        int charNum = str[i] - 'a' + 1;
        hashResult += charNum * pow(31, i);
    }
    cout << hashResult % 1234567891;
}