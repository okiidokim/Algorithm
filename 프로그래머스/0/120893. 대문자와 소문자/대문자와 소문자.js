function solution(my_string) {
    var answer = '';
    for (const c of my_string) {
        if (c.toLowerCase() === c) answer += c.toUpperCase();
        else answer += c.toLowerCase();
    }
    return answer;
}