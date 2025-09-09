#include<iostream>
#include<algorithm>
using namespace std;

struct JudgeType {
    int age;
    int index;
    string name;
};

bool comp(JudgeType a, JudgeType b) {
    if (a.age == b.age) return a.index < b.index;
    return a.age < b.age;
}

int main() {
    int n;
    cin >> n;
    JudgeType judge[n];
    for (int i = 0; i < n; i++) {
        cin >> judge[i].age >> judge[i].name;
        judge[i].index = i;
    }

    sort(judge, judge + n, comp);

    for (int i = 0; i < n; i++) {
        cout << judge[i].age << " " << judge[i].name << "\n";
    }

}