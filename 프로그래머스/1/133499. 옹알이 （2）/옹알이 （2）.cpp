#include <string>
#include<iostream>
#include <vector>
using namespace std;

string curr = "";

bool check(int index, string s, string ong) {
    if (index > s.length()-ong.length()) return false;
    if (curr == ong) return false;
    string next = s.substr(index, ong.length());
    if (next == ong) {
        curr = ong;
        return true;
    } 
    else return false;
}

int solution(vector<string> babbling) {
    int answer = 0;
    for (string s : babbling) {
        if (s.length() < 2) continue;
        bool flag = true;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'a') {
                flag = check(i, s, "aya");
                if (flag) i += 2;
                else break;
            } else if (s[i] == 'y') {
                flag = check(i, s, "ye");
                if (flag) i++;
                else break;
            } else if (s[i] == 'w') {
                flag = check(i, s, "woo");
                if (flag) i += 2;
                else break;
            } else if (s[i] == 'm') {
                flag = check(i, s, "ma");
                if (flag) i++;
                else break;
            } else {
                flag = false;
                break;
            }
        }
        if (flag) answer++;
        curr = "";
    }
    return answer;
}