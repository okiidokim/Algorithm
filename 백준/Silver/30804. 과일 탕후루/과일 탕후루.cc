#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    int s[n];
    unordered_map<int, int> fruit;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int left = 0, right = 0, max = 0;
    while(right < n) {
        fruit[s[right]]++;
        while(fruit.size() > 2) {
            fruit[s[left]]--;
            if (fruit[s[left]] == 0) fruit.erase(s[left]);
            left++;
        }
        max = max > right - left + 1 ? max : right - left + 1;
        right++;
    }
    cout << max;
}