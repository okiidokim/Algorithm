function solution(n) {
    var answer = 0;
    const maxIdx = Math.sqrt(n);
    for (let i = 1; i <= maxIdx; i++) {
        if (n/i === Math.floor(n/i)) answer++;
    }
    answer *= 2;
    if (n/maxIdx === Math.floor(n/maxIdx)) answer--;
    return answer;
}