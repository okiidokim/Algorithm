#include<iostream>
#include<algorithm>
using namespace std;

struct Point {
    int x;
    int y;
};

bool comp(Point p1, Point p2) {
    if (p1.y == p2.y) return p1.x < p2.x;
    return p1.y < p2.y;
}

int main() {
    int n;
    cin >> n;
    Point p[n];
    for (int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
    sort(p, p+n, comp);
    for (int i = 0; i < n; i++) cout << p[i].x << " " << p[i].y << "\n";
}