#include<iostream>
using namespace std;

int main() {
    long long sum;
    cin >> sum;
    long long currSum = 0;
    long long i = 1;
    while (sum > currSum) {
        i++;
		currSum += i;
    }
    cout << i - 1;
}