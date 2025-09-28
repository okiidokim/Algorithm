#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool comp(string a, string b) {
    return a + b > b + a;
} 

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    for (int n : numbers) {
        nums.push_back(to_string(n));
    }
    sort(nums.begin(), nums.end(), comp);
    if (nums[0] == "0") return "0";
    for (string s : nums) {
        answer += s;
    }
    return answer;
}