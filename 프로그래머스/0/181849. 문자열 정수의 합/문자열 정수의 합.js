function solution(num_str) {
    var answer = 0;
    for (const c of num_str) {
        const num = c.charCodeAt(0) - '0'.charCodeAt(0);
        answer += num;
    }
    return answer;
}