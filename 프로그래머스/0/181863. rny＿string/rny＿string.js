function solution(rny_string) {
    var answer = '';
    for (const c of rny_string) {
        if (c === 'm') answer += "rn";
        else answer += c;
    }
    return answer;
}