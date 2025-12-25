function solution(n) {
    var answer = [];
    const sqrtNum = Math.floor(Math.sqrt(n));
    for (let i = 1; i <= sqrtNum; i++) {
        if (Number.isInteger(n/i)) {
            answer.push(i);
            if (i !== n/i) answer.push(n/i);
        }
    }
    answer.sort((a,b) => a-b);
    return answer;
}