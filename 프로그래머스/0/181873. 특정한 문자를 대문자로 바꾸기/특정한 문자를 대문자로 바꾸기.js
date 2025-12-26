function solution(my_string, alp) {
    var answer = '';
    for (const c of my_string) {
        if (c === alp) answer += alp.toUpperCase();
        else answer += c;
    }
    return answer;
}