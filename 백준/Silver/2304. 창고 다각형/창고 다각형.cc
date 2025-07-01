#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int height[1001] = {0,};
    int maxH = 0, maxPos = 0, maxIndex = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        height[a] = b;
        if (maxH < b) {
            maxH = b;
            maxPos = a;
        }
        if (maxIndex < a) maxIndex = a;
    }
    int area = 0;
    for (int i = 0; i < maxPos; i++) {
        area += height[i];
        if (height[i+1] < height[i]) height[i+1] = height[i];
    }
    for (int i = maxIndex; i >= maxPos; i--) {
        area += height[i];
        if (height[i-1] < height[i]) height[i-1] = height[i];
    }
    cout << area;
}