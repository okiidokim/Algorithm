function solution(arr, k) {
    var answer = [];
    for (const n of arr) {
        if (k % 2 === 0) answer.push(n + k);
        else answer.push(n * k);
    }
    return answer;
}