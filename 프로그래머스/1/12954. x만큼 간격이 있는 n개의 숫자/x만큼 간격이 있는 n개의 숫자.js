function solution(x, n) {
    var answer = [];
    const d = x;
    for (let i = 0; i < n; i++) {
        answer.push(x);
        x += d;
    }
    return answer;
}