function solution(my_string) {
    var answer = '';
    for (const c of my_string) {
        if (c === 'a' || c === 'e' || c === 'i' || c === 'o' || c === 'u') continue;
        answer += c;
    }
    return answer;
}