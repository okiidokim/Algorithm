#include<iostream>
using namespace std;

struct Member {
    int weight;
    int height;
};

int main() {
    int n;
    cin >> n;
    Member mem[n];
    for (int i = 0; i < n; i++) {
        cin >> mem[i].weight >> mem[i].height;
    }
    
    int rank[n];
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 0; j < n; j++) {
            if (i==j) continue;
            if (mem[i].height < mem[j].height && mem[i].weight < mem[j].weight) cnt++;
        }
        rank[i] = cnt;
    }
    for (int i =0; i < n; i++) cout << rank[i] << " ";
}