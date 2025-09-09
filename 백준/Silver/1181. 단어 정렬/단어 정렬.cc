#include<iostream>
#include<algorithm>
using namespace std;

bool comp(string a, string b) {
    if (a.length() == b.length()) return a < b;
    return a.length() < b.length();
}

int main() {
    int n;
    cin >> n;

    string arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr+n, comp);

    cout << arr[0] << "\n";
    for (int i = 0; i < n; i++) 
        if (i > 0 && arr[i] != arr[i-1])
            cout << arr[i] << "\n";
}