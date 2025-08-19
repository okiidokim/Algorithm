function solution(s) {
    var answer = true;
    if (s.length === 4 || s.length === 6) {
        for (let c of s) {
            if (c <= '9' && c >= '0') continue;
            answer = false;
            break;
        }
    } else answer = false;
    return answer;
}