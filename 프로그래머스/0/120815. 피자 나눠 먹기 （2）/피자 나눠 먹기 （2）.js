function solution(n) {
    var answer = 0;
    for (let i = 1;; i++) {
        if ((i * 6) % n === 0) return i;
    }
    return answer;
}