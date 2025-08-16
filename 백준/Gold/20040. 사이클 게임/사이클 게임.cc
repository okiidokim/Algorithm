#include<iostream>
#include<vector>
using namespace std;

int parent[500000];

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a != b) parent[a] = b; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
        if (find(a) == find(b)) {
            cout << i+1;
            return 0;
        }
        unite(a, b);
	}
    cout << 0;
}