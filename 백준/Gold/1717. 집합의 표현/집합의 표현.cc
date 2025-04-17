#include<iostream>
using namespace std;

int parent[1000001];

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
    cin.tie(0);
    cout.tie(0);
    
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n+1; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int cal, a, b;
		cin >> cal >> a >> b;
		if (cal == 0) {
			unite(a, b);
		} else {
			if (find(a) == find(b)) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}