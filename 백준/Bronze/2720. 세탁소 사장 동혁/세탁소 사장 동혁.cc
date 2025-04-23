#include<iostream>
using namespace std;

int Quater = 25;
int Dime = 10;
int Nickel = 5;
int Penny = 1;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int c;
        cin >> c;
        int Qcnt = c/Quater;
        c %= Quater;
        int Dcnt = c/Dime;
        c %= Dime;
        int Ncnt = c/Nickel;
        c %= Nickel;
        cout << Qcnt << " " << Dcnt << " " << Ncnt << " " << c <<"\n";
    }
}