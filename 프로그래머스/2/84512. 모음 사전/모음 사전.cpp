#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

int solution(string word) {
    unordered_map<char,int> vowels;
    vowels.insert({'A', 0});
    vowels.insert({'E', 1});vowels.insert({'I', 2});
    vowels.insert({'O', 3});vowels.insert({'U', 4});
    int w[5] = {781, 156, 31, 6, 1};
    
    int answer = word.length();
    for (int i = 0; i < word.length(); i++) {
        answer += vowels[word[i]] * w[i];
    }
    return answer;
}

//A 1 
//AA 2
//AAA 3 
//AAAA 4
//AAAA(AEIOU) 56789

//AAAE 10 = (자리수)4 + (마지막자리수 경우)5 + (map)1
//AAAEA/EIOU/15
//AAAEA => (자리수)5 + vowels[word[i]] * (4-i) + vowels[word[i]]

//AAAI 16 자리수4 + (A, E 마지막 자리수 경우)10 + (map)2
//AAAI(AEIOU) 21
//AAAO 22 
//4 + 3*5 + 3 = 7 + 15 = 22
//AAAO(AEIOU) 27
//AAAU 28
//4 + 4*5 + 4
//AAAU(AEIOU) 33
//AAAUA -> 5 + 4*5 + 4
//AAAUE -> 5 + 4*5 + 4 + 1
//AAE 34 
//3 + 1*25 + 1*5
//word.length() + 



//E = 1 + 5 + 25 + 125 + 625 = 781
//AAAE = 4+6
//AAE = 3 + 31
//1 6 31 156 781
// word.length() + vowels[word[i]] + vowels[word[i]]*(4-i);
//
