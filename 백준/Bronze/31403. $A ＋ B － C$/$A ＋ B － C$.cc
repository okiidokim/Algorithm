#include<iostream>
#include<string>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int numResult = stoi(a) + stoi(b) - stoi(c);
    int strResult = stoi(a + b) - stoi(c);
    cout << numResult << "\n" << strResult;
}