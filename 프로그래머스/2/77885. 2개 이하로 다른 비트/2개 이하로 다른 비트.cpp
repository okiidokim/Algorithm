#include <string>
#include <vector>
#include <algorithm>
#include<cmath>
#include<iostream>
using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    
    for (long long n : numbers) {
        if (n % 4 != 3) {
            answer.push_back(n+1);
            continue;
        }
        
        string s = "";
        while (n > 0) {
            s += to_string(n%2);
            n /= 2;
        }
        reverse(s.begin(), s.end());
        int index = s.length() -1;
        for (int i = s.length()-1; i>= 0; i--) {
            if (s[i] == '0') {
                index = i;
                break;
            }
        }
        if (index < s.length() -1) {
            s = s.substr(0, index) + "10" + s.substr(index+2);
        } else {
            s = "10" + s.substr(1);
        }
        n = 0;
        for (int i = 0; i < s.length(); i++) {
            n += (s[i]-'0') * pow(2, s.length() - 1 -i);
        }
        answer.push_back(n);
    }
    return answer;
}