function solution(arr) {
    var answer = [];
    for (const n of arr) {
        for (let i = 0; i < n; i++) {
            answer.push(n);
        }
    }
    return answer;
}