function solution(strArr) {
    var answer = [];
    let idx = 0;
    for (const str of strArr) {
        if (idx % 2 == 0) answer.push(str.toLowerCase());
        else answer.push(str.toUpperCase());
        idx++;
    }
    return answer;
}