function solution(n) {
    const sqrtNum = Math.sqrt(n);
    if (sqrtNum % 1 === 0) return 1;
    return 2;
}