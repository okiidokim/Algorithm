//20:25 ~ 
#include <string>
#include <vector>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int y = stoi(today.substr(0, 4));
    int m = stoi(today.substr(5, 2));
    int d = stoi(today.substr(8, 2));
    unordered_map<char, int> term;
    for (string s : terms) {
        char alpha = s[0];
        int month = stoi(s.substr(2));
        term.insert({alpha, month});
    }
    
    for (int i = 0; i < privacies.size(); i++) {
        string s = privacies[i];
        int yy = stoi(s.substr(0, 4));
        int mm = stoi(s.substr(5, 2));
        int dd = stoi(s.substr(8, 2));
        char alpha = s[11];
        int leftM = term[alpha];
        
        yy += leftM / 12;
        mm += leftM % 12;
        
        if (mm > 12) {
            mm -= 12;
            yy++;
        }
        
        if (yy < y) answer.push_back(i+1);
        else if (yy == y && mm < m) answer.push_back(i+1);
        else if (yy == y && mm == m && dd <= d) answer.push_back(i+1);
    }
    return answer;
}