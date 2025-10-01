// 13:20 ~ 13:40
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include<iostream>
using namespace std;

struct Music {
    string gen;
    int plays;
    int idx;
};

bool comp(pair<string,int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool comp2(Music a, Music b) {
    return a.plays > b.plays;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> mp;
    for (int i = 0; i < plays.size(); i++) {
        pair<map<string, int>::iterator, bool> pr = mp.insert({genres[i], plays[i]});
        if (!pr.second) mp[genres[i]] += plays[i];
    }
    
    vector<pair<string, int>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), comp);
    map<string, int> cnt;

    vector<Music> mus;
    for (int i = 0; i < plays.size(); i++) {
        mus.push_back({genres[i], plays[i], i});
    }
    sort(mus.begin(), mus.end(), comp2);
    
    for (int i = 0; i < vec.size(); i++) {
        auto [gen, p] = vec[i];
        for (Music m : mus) {
            if (m.gen != gen) continue;
            pair<map<string,int>::iterator, bool> pr = cnt.insert({m.gen, 1});
            if (!pr.second) cnt[m.gen]++;
            if (cnt[m.gen] > 2) break;
            answer.push_back(m.idx);
        }
    }
    
    return answer;
}